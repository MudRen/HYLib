// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������̫ԭ����20�������壬�ں�Ͽ�����.���ڹŰزԴ䡣
��������߷��̫ԭ�������������������ڴ���������������
�б��ǡ��ִ�ɽ�š���ͤ�����ȶ���Ԫ��������(1343��)�ؽ�����
���������ν�ʱ�ڷ��������ͤ���󣬺��������ô������������
�棬�ṹ�������Ͻ���Ϊ��Ԫ��������������������Ȫ����ʯɽ����
��ӿ����ˮ�½ϵͣ��˳ơ���Ȫ��������ʯ��Ȫ��Ϊ̫ԭ��ʤ֮һ��
LONG );
	set("exits", ([
//		"east"  : "/d/leshou/road4",
 		"northwest"  : __DIR__"road6",
//		"southwest"  : "/d/xucheng/dadao12",
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



