// Room: /d/jindezheng/doctor-room.c

inherit ROOM;

void create()
{
	set("short", "��ҽ��");
	set("long", @LONG
��ҽ����ϰ�Ҷ��ʿ,���ֻش�,ҽ����տ,�˳���ҽ��.���ܴ�С 
��,ֻҪû����,�����ܰ��˸��Ȼ���,����Ƣ���Ź��˵�.��˵�������� 
���˵����,����ǰ�Ӻ��ݶ��������˵�,�����⿪�˸�ҩ��,�β�����. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"street1",
]));
	set("no_fight", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/doctor.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
