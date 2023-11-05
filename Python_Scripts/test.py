import cv2

# Load an image from file (provide the path to your image file)
image_path = 'C://Users//DELL//Desktop//ITI_GP//ADAS_Multi_mode_System//Python_Scripts//OBTQ.jpg'

image = cv2.imread(image_path)

if image is None:
    print("Error: Failed to load the image.")
else:
    # Display the loaded image in a window
    cv2.imshow("Loaded Image", image)

    # Wait for a key press and close the window when any key is pressed
    cv2.waitKey(0)
    cv2.destroyAllWindows()
