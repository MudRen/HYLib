//jinling  yuhuatai.c
inherit ROOM;

void create()
{
        set("short", "�껨̨");
        set("long", @LONG
�ഫ�����ʱ����ɮ�ƹⷨʦ�ڴ˽������ж����棬�����仨���꣬��
�˼���Ϊ�껨̨���껨̨����ʱ��ʯ�Ӹڣ�������ʢ�� ɫ�ʰ�쵵����ʯ��
���ֳƾ۱�ɽ����觸ڡ�ֻ�������ؽ��ǲ�ɫ��ʯͷ,�����껨֮����
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"jiangdao1",
           "south" : __DIR__"beijie1",

]));
        set("objects", ([
		__DIR__"npc/obj/stone" : 4,
               __DIR__"npc/wangqier" : 1,

			]) );

//        set("no_clean_up", 0);
//       set("no_death_penalty",1);

        setup();
        replace_program(ROOM);
}
