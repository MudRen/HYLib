// Room: /d/jindezheng/jindezhen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ǽ�������,�˵س����Ĵ�������ȫ������,��������,������ 
�˴����Ƶ��໨��,�����,�۲ʴ�,��ɫ�Դ�,���Ǵ����еľ�Ʒ,Ϊ�� 
����,�����ھ��ھ������һ��С����,�ֵ������ֱ߾���һ���մɵ�. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 3 */
//  "northup" : "/d/hangzhou/lu4.c",
  "west" : __DIR__"street1",
  "south" : __DIR__"china-shop",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiongmao.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
