// "suiye"/nanchengmen
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ϳ���");
	set("long", @LONG
��������Ҷ���ϳ��ţ��������������ֺ��ܶ������������Ҷ����
�Լ�����ʿ�������������һ������Ů�˺ͲƱ���
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"dadao1",
		"north" :  __DIR__"nandajie2",
               
	]));
 set("objects",([ __DIR__"npc/guanbing":2,]));
       setup();
	replace_program(ROOM);
}	
