// Room in ����
inherit ROOM;
void create()	
{
	set("short", "��Ժ");
	set("long", @LONG	
������һ����Ժ��̧ͷ���Կ���һ�����ң�����д�ţ��龲�¡���
����ԭ��ɮ���������ƹܵ���Ժ�����ڸ�������𷨡����洫��������
���з�֮�������������Զ�����ò�Ϣ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"east" : __DIR__"caodi1",
		"enter":__DIR__"baodian",
       	]));
       set("objects",([
         __DIR__"npc/sengren":1,
         ]));
       setup();
	replace_program(ROOM);
}	
