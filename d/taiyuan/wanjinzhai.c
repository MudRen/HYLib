// /d/taiyuan/wanjingzhai.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "���ի");
	set("long", @LONG
��˵���Ǯׯ�Ķ������ڳ��д�Ա�������ۺ��ڹ��ڸ��ض��з�
�ţ�����������ȫ��ͨ�У���Զ����³������ͻ��Ҳ��ͨ�С��������
�ϰ�������Σ���������û�˴���
LONG
	);
set("exits", ([
                "west" : __DIR__"nandajie1", 
	]));
 set("objects",([ __DIR__"npc/huoji":1,]));
       setup();
	replace_program(ROOM);
}	
