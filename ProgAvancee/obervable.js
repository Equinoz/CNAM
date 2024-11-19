function anObservable(observer) {
	for (let i=1; i<11; i++) {
		setTimeout(() => observer(i + 40), i * 500);
	}
}

anObservable(data => console.log(data));
