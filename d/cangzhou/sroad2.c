// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
        set("outdoors", "����");
        set("exits", ([ 
                "north" : __DIR__"sroad1",
                "southeast" : __DIR__"sroad3",
        ]));
        set("no_clean_up", 0);

        setup();
}
