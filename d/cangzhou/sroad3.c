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
                "northwest" : __DIR__"sroad2",
                "southeast" : __DIR__"sroad4",
        ]));
        set("no_clean_up", 0);

        setup();
}
