// /d/zhuojun/yueqidian.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�߽�������ֻ���������̨�Ϻ����ܵ�ǽ�ϰ����˸�ʽ������������
���������������˺��Ļҳ�������ܾ�û�����ʽ����
LONG
	);
set("exits", ([
		"south" :__DIR__"dongdajie1",
	]));
       setup();
	replace_program(ROOM);
}	
