// Room: houyuan.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��Ժ");
	set("long", @LONG
��Ժ�˽���������֮����һ�Ų軨�������������������������Ӻ�����
�֡���ǽ����һ�ų����ӣ��������Щˮ��������һֻ��ˮ������ֻ���С��
ϴ�øɸɾ�����������һƬ���֣�Ҳ���������ɵĽ��ء�
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"jhg",
            "north" : __DIR__"songlin1",	    
        ]));
        set("outdoors", "����");
	setup();
        replace_program(ROOM);
}
