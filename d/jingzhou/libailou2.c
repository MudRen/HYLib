// Room: libailou2.c
// congw 980830
inherit ROOM;


void create()
{
        set("name", "���¥");
        set("short", "���¥��¥");
	set("long", @LONG
	����������������ѧʿ������������ʫ��������������Ҳ������߳Ժȱ�
�����ס�����Ҳ�ǳ���ٰ�ϲ�����ѳ�������վ��¥��������ֻ�����Ŀ�������
������һ�غ�ˮ���̲������������ǳ�ɽ���룬��������Կ�������ȫ���İ�¹��
Ժ�ĺ�ͥ��ǽ�Ϲ��ż۸�����(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));


	set("exits", ([
                "down" : __DIR__"libailou",
	]));

	setup();
	replace_program(ROOM);
}
