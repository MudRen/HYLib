// /d/zhuojun/yizhan.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����լ");
	set("long", @LONG
�����լ�ǳ�ɳ�����ִ�����Ĺż������潭����̫ƽ��̫����
����Ԫǰ176�꣬�Ż�����ĺ�����Һ�˼��Ҽ����Ϊ��ɳ��̫��
���ڳ�ɳ�ȹ�4��ʱ�⣬���ڴ�д����ǧ����ƪ������ԭ�����͡���
�񸳡��������ʱ�������լ�������ΰ��á�������������¥��
����ͤ�Ƚ�����
LONG
	);
set("outdoors", "changsha");
set("exits", ([
                "south"  :__DIR__"xidajie1",
	]));
       setup();
	replace_program(ROOM);
}	
