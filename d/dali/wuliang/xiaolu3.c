// Room: xiaolu3.c
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
	    "southdown" : __DIR__"xiaolu2",
	    "northup" : __DIR__"xiaolu4",
        ]));

        set("outdoors", "����");

	setup();
        replace_program(ROOM);
}
