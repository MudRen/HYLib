// Room: /d/jingzhou/shop.c
//980829 /congw
inherit ROOM;

void create()
{
        set("short", "��԰");
	set("long", @LONG
�㿴�����ܷ������£�������һ�������˶����԰�ӣ�������������ͻҳ���ʹ��
���ɵ���Ȼ���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dongdajie2",
]));
        set("no_clean_up", 0);

       setup();
        replace_program(ROOM);
}
 
