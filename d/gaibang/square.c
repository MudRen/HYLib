inherit ROOM;

void create()// square.c


{
        set("short", "���䳡");
        set("long", @LONG
������ؤ������䳡���������⼸��ľ�ˣ�ͨ�������ؤ��ĵ�����
��ϰ��������
LONG );
        set("exits", ([ /* sizeof() == 2 */        
            "south"     : __DIR__"mishi",       
        ]));
        set("objects", ([
            "/d/shaolin/npc/mu-ren" : 5,
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
}
 
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam=(mapping)me->query("family");
        if ((!myfam ||myfam["family_name"] != "ؤ��") && (dir == "east"))
                return notify_fail(
"�Ǳ���ؤ������䳡����λ" + RANK_D->query_respect(me) + "��ֹ����\n");
        return ::valid_leave(me, dir);
}

