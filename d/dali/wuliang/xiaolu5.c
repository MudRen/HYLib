// Room: xiaolu5.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "��ʯ̨��");
	set("long", @LONG
��������ʯ���ɵ�̨�ף�������������������Ϊ����������ʯһ��һ��ֱ
�̵�������̨�����߻��������ˡ�̨�����ܳ���һЩҰ�ݣ�ͷ����һЩ��֪��
��С����������ȥ��
LONG
	);
	set("exits", ([ 
	    "eastdown" : __DIR__"xiaolu4",
	    "northup" : __DIR__"wljmen",
        ]));

        set("outdoors", "����");

	setup();
        replace_program(ROOM);
}
