#include "AUXIO.h"

AUXO::AUXO(uint8_t pin, uint8_t mode)
{
    _pin = pin;
    _mode = mode;

    if(_mode == LOW)
    {
        _on = 0;

    }
    else
    {
        _on = 1;
    }
}

bool AUXO::begin(void)
{
    if(_pin > 30)
    {
        errorMessage = "Error AUXO object. pin configuration is in wrong range.";
        return false;
    }

    bcm2835_gpio_fsel(_pin, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(_pin, !_on);

    return true;
}

AUXI::AUXI(uint8_t pin, uint8_t pud)
{
    _pin = pin;
    _mode = pud;
}

bool AUXI::begin(void)
{
    if(_pin > 30)
    {
        errorMessage = "Error Button object: pin configuration is in wrong range.";
        return false;
    }

    bcm2835_gpio_fsel(_pin, BCM2835_GPIO_FSEL_INPT);
    bcm2835_gpio_set_pud(_pin, _mode);

    return true;
}