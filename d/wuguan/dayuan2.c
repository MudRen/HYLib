//cool 98.4.18
inherit ROOM;

void create()
{
	set("short", "��ݴ�Ժ");
	set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��ǿ������
�ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����ˮ�ĴҴҶ�����������
��̨�׾�����ݴ���.��
LONG);
	set("exits", ([
		"south" : __DIR__"dayuan",
       	        "northup" : __DIR__"dating",
        ]));
        set("objects", ([
           __DIR__"npc/zhangfeng" : 1,
                   ]));
           set("no_fight",1);
	setup();
        replace_program(ROOM);
}


