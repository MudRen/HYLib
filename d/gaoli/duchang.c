// /d/gaoli/duchang
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�����ĳ�");
	set("long", @LONG
�����Ǹ���������һ�Ҷķ�����ҹĻ���ٺ�����͸������֡�
���ú����Ĵ������������ů�ͻ��֣������л�����ϵ�֬�۵�������
��Ǯ�û�������һ��������ö���������
LONG	
       );
set("exits", ([
                "east":__DIR__"zhuque-2",    
	]));
       setup();
	replace_program(ROOM);
}
