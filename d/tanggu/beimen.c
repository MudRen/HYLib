
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����������");
	set("long", @LONG
������������ڵı������ˣ����ſ�һ�Ӷӹٱ������̲�����İ��ա�һ
���ֳֳ��������׵��佫���ſ�Ѳ�ӡ����ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG );
	set("exits", ([
		"south" : __DIR__"stbeijie2",
//                "northeast" : "/d/daizhou/guandao1",
	]));

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("outdoors", "����");

	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n";
}
