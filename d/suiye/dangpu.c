// "suiye"/dangpu
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
��������ҶΨһ��һ�ҵ��̡����žͿ���һ������ͭƤ�Ĵ��̨��
�Ե�ʮ�����ɡ��ڹ�̨��������һ�����ݵ������۵���������һ�����
��˯�����ӣ������ǵ�ֵ������ˡ��ڹ�̨�Ա�����һ�����ӣ�paizi)��
����д��һЩ�䵱�Ĺ�ء�
LONG
	);
set("exits", ([
		
                "south"  :__DIR__"dongdajie1",
	]));
	set("objects",([
	__DIR__"npc/zhou":1,
	]));
       setup();
	replace_program(ROOM);
}	
