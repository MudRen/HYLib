//ROM diabio

inherit ROOM;

void create()
{
	set("short","��Ż���������");
        set("long",
         "�����������ԭ����ġ���Ż��������Ĵ��š������Ͽ����ձ���ս��\n"
         "���ܵ�ǽ�ھ��ø�ɫľͷ���ɣ����ڷ紵��ɹ�Ѿ��е���ɫ�ˡ�������\n"
         "�ܿ������յĻԻ�\n"
        );
        set("outdoors", "feitian");
        set("exits", ([
		"north" : __DIR__"qianting",
                "southdown" : __DIR__"jiedao",
        ]));
        set("objects",([
                __DIR__"npc/dizi" : 2,
	]));
	setup();
}
