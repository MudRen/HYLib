// "suiye"/dongchengmen
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
��������Ҷ�Ķ����š�����͵��˳��У�Զ����ͷ�ܶ����˻��Ǻ�
��Ķ���ͨ���л���½����������һЩִ�ڵ���ʿ��ʱ����������̫ƽ����
һ����ʿ����Ӣ�˲���������Ķ���������ʿ��
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east"  : __DIR__"caoyuan1",
               
	]));
 set("objects",([ __DIR__"npc/guanbing":2,]));
       setup();
	replace_program(ROOM);
}	
