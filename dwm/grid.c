void
grid(Monitor *m) {
	unsigned int i, n, cx, cy, cw, ch, aw, ah, cols, rows;
	Client *c;

	int gap = m->gappx;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next))
		n++;

	/* grid dimensions */
	for(rows = 0; rows <= n/2; rows++)
		if(rows*rows >= n)
			break;
	cols = (rows && (rows - 1) * rows >= n) ? rows - 1 : rows;

	/* window geoms (cell height/width) */
	ch = m->wh / (rows ? rows : 1);
	cw = m->ww / (cols ? cols : 1);
	for(i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
		cx = m->wx + (i / rows) * cw + gap;
		cy = m->wy + (i % rows) * ch + gap;
		/* adjust height/width of last row/column's windows */
		ah = ((i + 1) % rows == 0) ? m->wh - ch * rows : 0; ah -= gap;
		aw = (i >= rows * (cols - 1)) ? m->ww - cw * cols : 0; aw -= gap;
		resize(c, cx, cy, cw - 2 * c->bw + aw, ch - 2 * c->bw + ah, False);
		i++;
	}
}

