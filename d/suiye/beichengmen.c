// "suiye"/beichengmen
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
��������Ҷ�ı����š��Ͼ͵��˳��У�Զ��ϡϡ����û�����ˡ���
������һЩִ�ڵı�ʿ����ʮ��ͻ����ʿӢ�˲������ϸ�ļ�������
���ˡ�
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"beidajie1",
//                "north" : ""suiye"out/out1",
	]));
 set("objects",([ __DIR__"npc/guanbing":2,]));
       setup();
	replace_program(ROOM);
}	
