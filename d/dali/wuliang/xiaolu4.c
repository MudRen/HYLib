// Room: xiaolu4.c
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
	    "southdown" : __DIR__"xiaolu3",
	    "westup" : __DIR__"xiaolu5",
        ]));

        set("outdoors", "����");

	setup();
        replace_program(ROOM);
}
