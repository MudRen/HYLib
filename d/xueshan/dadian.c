//      dadian.c ���
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
������ѩɽ�µĴ����빩���ŷ�������ɮ����
�����ž��ġ�Զ����������������ϵ�Ĥ�ݡ��������
���ǲ�
LONG );
        set("exits",([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/lazhang" : 1,
		__DIR__"npc/xiang-ke" : 2,
		"/d/biwu/champion_xs":1,
		"/quest/menpaijob/xueshan/lj/banchan":1,
        ]));
        set("valid_startroom", 1);
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

        "/clone/board/xueshan_b"->foo();
}
