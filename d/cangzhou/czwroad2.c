// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
        set("outdoors", "���ݳ�");
        set("exits", ([ 
                "east" : "/d/cangzhou/wroad1",
                "southwest" : "/d/cangzhou/wroad3",
        ]));
	set("group", 1);
        setup();
}
