USE realestatedb;

DROP TABLE IF EXISTS contact;
DROP TABLE IF EXISTS banner;
DROP TABLE IF EXISTS featured;
DROP TABLE IF EXISTS service;

CREATE TABLE contact (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    phone VARCHAR(32) NOT NULL,
    email VARCHAR(32) NOT NULL,
    location VARCHAR(512) NOT NULL,
    latitude DECIMAL(10, 8) NOT NULL,
    longitude DECIMAL(11, 8) NOT NULL,
	facebook VARCHAR(64),
	youtube VARCHAR(64)
) DEFAULT CHARSET=utf8;

INSERT INTO contact(phone, email, location, latitude, longitude, facebook, youtube) VALUES
    ('+1 234 567 8901', '1@example.com', '786 Main Road, hollies, California, USA', 11.5564, 104.9282, 'https://www.facebook.com/ohahlev', 'https://www.youtube.com/channel/UCW5ecqlRPhjLMramP3HnZjQ');


CREATE TABLE banner (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    html VARCHAR(1024) NOT NULL 
) DEFAULT CHARSET=utf8;

INSERT INTO banner (html) VALUES 
    ('
      <h1>Perfect Property</h1>
      <h4 class="text-uppercase mt-md-3 mt-2 mb-md-4 mb-3">for your home</h4>
      <p class="text-white">Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation
        ullamco laboris</p>
      <a href="/about" class="banner-button btn mt-md-5 mt-4">Know More</a>
    ');

CREATE TABLE featured (
  id INTEGER AUTO_INCREMENT PRIMARY KEY,
  image VARCHAR(32) NOT NULL,
  html VARCHAR(10240) NOT NULL
) DEFAULT CHARSET=utf8;

INSERT INTO featured(image, html) VALUES
  ('/images/bg.jpg', 
  '
						<h4>A Beautiful Beach House</h4>
						<h6 class="mt-3 mb-xl-5 mb-4">Excepteur sint occaecat</h6>
						<p>sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation
							ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>
						<ul class="list-beach mt-lg-5 mt-4">
							<li>
								<div class="row">
									<div class="col-1 text-center">
										<i class="fas fa-hand-point-right"></i>
									</div>
									<div class="col-10">
										<p>Totam rem aperiamet quasi architecto beatae vitae dicta sunt explicabo beatae vitae dicta.</p>
									</div>
								</div>
							</li>
							<li class="my-3">
								<div class="row">
									<div class="col-1 text-center">
										<i class="fas fa-hand-point-right"></i>
									</div>
									<div class="col-10">
										<p>A rchitecto beatae Totam rem aperiamet quasi architecto beatae vitae dicta sunt explicabo.</p>
									</div>
								</div>
							</li>
							<li>
								<div class="row">
									<div class="col-1 text-center">
										<i class="fas fa-hand-point-right"></i>
									</div>
									<div class="col-10">
										<p>Dicta sunt explicabo Totam rem aperiamet quasi architecto beatae vitae dicta sunt explicabo.</p>
									</div>
								</div>
							</li>
						</ul>
					'
  );

  CREATE TABLE service (
    id INTEGER AUTO_INCREMENT PRIMARY KEY,
    icon VARCHAR(32) NOT NULL,
    name VARCHAR(32) NOT NULL,
    subline VARCHAR(128) NOT NULL
  ) DEFAULT CHARSET=utf8;

INSERT INTO service(icon, name, subline) VALUES
  ('fas fa-key', 'Renting Service', 'Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.'),
  ('far fa-building', 'Property Management', 'Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.'),
  ('far fa-money-bill-alt', 'Saling Service', 'Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.'),
  ('fas fa-clipboard-list', 'Property Listing', 'Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.'),
  ('fas fa-user-secret', 'Non Stop Security', 'Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.'),
  ('fas fa-wrench', 'Luxurious Fittings', 'Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.');
