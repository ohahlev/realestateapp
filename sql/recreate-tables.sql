USE realestatedb;

DROP TABLE IF EXISTS contact;
DROP TABLE IF EXISTS banner;

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

CREATE TABLE banner (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    text VARCHAR(1024) NOT NULL
) DEFAULT CHARSET=utf8;

INSERT INTO banner(text) VALUES 
    ('
      <h1>Perfect Property</h1>
      <h4 class="text-uppercase mt-md-3 mt-2 mb-md-4 mb-3">for your home</h4>
      <p class="text-white">Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation
        ullamco laboris</p>
      <a href="about.html" class="banner-button btn mt-md-5 mt-4">Know More</a>
    ');