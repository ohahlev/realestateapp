USE realestatedb;

DROP TABLE IF EXISTS contact;

CREATE TABLE contact (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    phone VARCHAR(32) NOT NULL,
    email VARCHAR(32) NOT NULL,
    location VARCHAR(512) NOT NULL,
    latitude DECIMAL(10, 8) NOT NULL,
    longitude DECIMAL(11, 8) NOT NULL
) DEFAULT CHARSET=utf8;

INSERT INTO contact(phone, email, location, latitude, longitude) VALUES
    ('+1 234 567 8901', '1@example.com', '786 Main Road, hollies, California, USA', 11.5564, 104.9282);
