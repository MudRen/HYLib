// Room: /city/zuixianlou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����¥ƽ���ֵ�");
	set("long", @LONG
��Բ����������������¥����˵�����˲�֪�����˲�����������ѧʿ��
�ε��ˣ�������¥�Ļ�����޲����ڣ���ȻΪ�����ң�����һ�δ��麣�ڵ�
�ѻ����Ӵ�����¥��������¥�²��ü��ף��˿Ͷ��ǴҴҵ����ˣ�����
�ӡ����ȡ��׾ƾ͸�·ȥ�ˡ�¥����������
LONG );
	set("exits", ([
		"south" : __DIR__"west3",
		"up" : __DIR__"zxlpath",
	]));
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

