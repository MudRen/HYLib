inherit ROOM;
void create()
{
        set("short", "Ǯׯ");
        set("long", @LONG
����ȫ����ģ����һ��Ǯׯ����ȫ�����ض��зֵꡣ�����Ĵ���������
�Ĺ�̨������ɨ�ĸɸɾ�������̨�󼸸��˷�������С�����æ�Ľ�ͷ�ö
�ϰ�ȴ����Ȳ����졣
LONG );
        set("exits", ([
                "east" : __DIR__"stnanjie2",
	]));

	set("objects", ([
                __DIR__"npc/zhu" : 1,
		__DIR__"npc/huoji" : 1,
      	]));

	setup();
}
