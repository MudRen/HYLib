// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
        set("outdoors", "����");
        set("exits", ([ 
                "east" : __DIR__"wroad3",
                "southwest" : "/d/cangzhou/eroad4",
        ]));

        set("no_clean_up", 0);

        setup();
}
