import random

# --- Trạng thái toàn cục ---
cx = None  # x của boss 36 đầu tiên
cy = None  # y của boss 36 đầu tiên
step_count = 0  # đếm số bước đi từ center36
max_steps = 20  # đi tự do 20 bước trước khi quay về
current_pos = None  # ghi lại vị trí hiện tại


def getNextPoint(x, y, lastBossID):
    global cx, cy, step_count, current_pos
    step_size = 50  # bước cơ bản quanh boss 36

    current_pos = (x, y)

    # Nếu vừa gặp boss ID=36 lần đầu, thiết lập tâm
    if lastBossID == 36 and cx is None and cy is None:
        cx, cy = x, y
        step_count = 0

    # Nếu chưa có center36 → khám phá rộng để tìm boss 36
    if cx is None or cy is None:
        # đi xa hơn: 4 * step_size
        nx = x + 4 * step_size * random.choice([-1, 0, 1])
        ny = y + 4 * step_size * random.choice([-1, 0, 1])
        return nx, ny

    # Nếu đã có center36 → đi random trong 20 bước, sau đó quay về center
    if step_count < max_steps:
        # đi random quanh center36
        dx = random.choice([-1, 0, 1]) * step_size
        dy = random.choice([-1, 0, 1]) * step_size
        step_count += 1
        return x + dx, y + dy
    else:
        # quay về center36
        step_count = 0
        return cx, cy
