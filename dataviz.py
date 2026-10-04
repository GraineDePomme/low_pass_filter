import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path
import imageio.v2 as imageio

data_dir = Path("data")
output_dir = Path("img")

rc = 0.01

for csv_file in sorted(data_dir.glob("*.csv")):
    data = pd.read_csv(csv_file)

    plt.plot(data["t"], data["vin"], label="Vin")
    plt.plot(data["t"], data["vout"], label="Vout", linestyle="--")

    plt.xlabel("Time (s)")
    plt.ylabel("Voltage (V)")
    plt.title("Low-pass filter (RC =" + str(round(rc, 3)) + ")")
    plt.legend()
    plt.grid()

    output_file = output_dir / f"{csv_file.stem}.png"
    plt.savefig(output_file, dpi=150)
    plt.close()

    print(f"Saved {output_file}")

    rc += 0.01



images = []
for png_file in sorted(output_dir.glob("*.png")):
    images.append(imageio.imread(png_file))

imageio.mimsave(
    "animation.gif",
    images,
    duration=0.1,
    loop=0
)