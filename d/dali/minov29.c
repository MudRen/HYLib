//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������¥���в������Ჿ�������ã����г��Ϸ�Ҫ�ձ��ڴ˾�
�����ڴ��£�Ҳ�ڴ˽Ӵ������ͣ�����������ٸ�������ʹ�ߡ�
�����Ա����ͼ�ڱڻ�������Ƥëװ���ıڡ�
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov80",
		"up" : __DIR__"minov30",
		]));

	set("objects", ([
		__DIR__"npc/tyzuzhang" : 1,
	]));

	set("cost", 2);
	setup();
}
