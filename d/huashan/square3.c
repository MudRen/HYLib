// square.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����ǻ�ɽ�ɵ����䳡���������⼸��ľ�ˣ������Ǳ����⣬������
��С�ꡣͨ������໪ɽ�ɵ����ڴ�ϰ�����������ߵķ������Ϲ���һ��
�ң����顸Ⱥ�ɹۡ����������ƺ�����С��ͨ��ɽ�ϡ�
LONG );
        set("exits", ([ /* sizeof() == 2 */         
            "north"     : __DIR__"bingqifang"
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
        if ((!myfam ||myfam["family_name"] != "��ɽ��") && (dir == "east"))
                return notify_fail(
"�Ǳ��ǻ�ɽ�ɵı����⣬��λ" + RANK_D->query_respect(me) + "��ֹ����\n");
        return ::valid_leave(me, dir);
}
