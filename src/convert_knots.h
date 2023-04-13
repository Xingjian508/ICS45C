double knots_to_miles_per_minute(int knots) {
    double feetPerHour = 6076 * knots;
    double milePerHour = feetPerHour / 5280;
    double milePerMinute = milePerHour / 60;
    return milePerMinute;
}

