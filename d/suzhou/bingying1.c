inherit ROOM;

void create()
{
        set("short", "��Ӫ");
        set("long", @LONG
�����Ǳ�Ӫ���������鵽�����ǹٱ����е����佫��ָ�����жӲ������е�
�������������е����š�����������Ϣ����ǽ��������˧��������ɫ��Ѱ������
�ܡ�
LONG
        );

        
        set("exits", ([
                "west" : __DIR__"jail",
                "east" : __DIR__"beimen",
        ]));

        set("objects", ([
                __DIR__"npc/liangdong" : 1,
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 4,
        ]));

        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("zhao liangdong", environment(me))) && 
                dir == "west")
                return notify_fail("�����������ȵ��������˵ȣ�һ���뿪��\n");

        return ::valid_leave(me, dir);
}

