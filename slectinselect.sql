#在阿根廷Argentina 及 澳大利亞 Australia所在的洲份中，列出當中的國家名字 name 及洲分 continent 。按國字名字順序排序

SELECT name,continent

FROM world

WHERE continent in (SELECT continent FROM world WHERE name='Argentina' or name = 'Australia')

 order by name asc
