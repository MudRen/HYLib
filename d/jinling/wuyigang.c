//jinling  wuyigang.c
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������һ���ľ���С������.�ഫ˵��ʱ��л�ӵ��������£����������
�е���:����ȸ�ű�Ұ�ݻ����������Ϧ��б����ʱ��л��ǰ�࣬����Ѱ��
���ռҡ�������Ҳ��˶������ĺ���
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "south" : __DIR__"dongjie1",
          "east" : __DIR__"yantang",


]));
        set("objects", ([
//"/u/poor/beggar/npc/beggar" : 4,
              __DIR__"npc/armorseller" : 1,
			]) );

     set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
