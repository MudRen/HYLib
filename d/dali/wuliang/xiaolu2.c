// Room: xiaolu2.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��ʯС·");
	set("long", @LONG
��������ʯ�̳ɵ�С·��·���ϼ�����һЩ��ɳ��С·���߳���һЩҰ�ݣ�
��������Ұ��Ʈ�������㡣��������ɭɭ��ԭʼ���֣���ʱ����һ�����Ұ
�޽���, ͷ����һЩ��֪����С����������ȥ��
LONG
	);
	set("exits", ([ 
	    "northup" : __DIR__"xiaolu3",
            "northeast" : __DIR__"lsdui",
	    "westdown" : __DIR__"xiaolu1",
        ]));

        set("outdoors", "����");

	setup();
        replace_program(ROOM);
}
