// /d/taiyuan/qibaozhai.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�뱦ի");
	set("long", @LONG
����һ�������Զ�ĵ��̣��۸񹫵���ͯ�����ۣ�����䵱������
��ʮ�ַ��ģ���̨��һλ�Ϲ����ϸ�Ŀ�������ĵ䵱Ʒ�����ﲻ��
һ������ζ��
LONG
	);
set("exits", ([
                "west" : __DIR__"nandajie2", 
	]));
	set("objects",([
	__DIR__"npc/sun":1,
	]));
       setup();
	replace_program(ROOM);
}	
