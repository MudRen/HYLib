// river.c Ϫ��
#include <room.h>
inherit ROOM;
void create()
{
        set("short","СϪ��");
	set("long",@LONG
������ɽ·ǰ���������һ��Ϫ�ߡ������������յñ�����ˮ������
������һ��ƽ�һ�㣬׳���ޱȣ���վ���������ʲôҲ��Ը���룬ֻϣ��
�������쳤�ؾã�ʱ�����㡣
LONG
);
        set("outdoors","����");

        set("exits",([ 
	    "south": __DIR__"shanlu1",
        ]));

	setup();
}

void init()
{
        add_action("do_look","look");
        add_action("do_jump",({"tiao", "jump", "yue"}));
}

int do_look(string arg)
{
        object me,room;
        me = this_player();
        if(!( room = find_object(__DIR__"boat")))
          room = load_object(__DIR__"boat");
        if ( room->query("ppl") > 0){
        set("long", @LONG
������ɽ·ǰ���������һ��Ϫ�ߡ������������յñ�����ˮ������
������һ��ƽ�һ�㣬׳���ޱȣ���վ���������ʲôҲ��Ը���룬ֻϣ��
�������쳤�ؾã�ʱ�����㡣
LONG
);
        me->look(arg);
        }
        else {
        if (!arg) {
        set("long", @LONG
������ɽ·ǰ���������һ��Ϫ�ߡ������������յñ�����ˮ������
������һ��ƽ�һ�㣬׳���ޱȣ���վ���������ʲôҲ��Ը���룬ֻϣ��
�������쳤�ؾã�ʱ�����㡣���ذ��ػ����Σ�����Ϫ�к�������С�ۡ�
LONG
        );
        me->look(arg);
        }
        else if(arg == "boat" || arg == "zhou") {
          write("һҶС�ۣ�ƮƮ����������Ϫ����������ȥ��\n");
          me->set_temp("jqg/look", 1);
          return 1;
          }
       }                
}

int do_jump(string arg)
{
        object me,room,*ob;
        int i;
        me = this_player();
        if(!( room = find_object(__DIR__"boat")))
          room = load_object(__DIR__"boat");
        if( !me->query_temp("jqg/look")) return 0;
        if( !arg ||(arg != "boat" && arg != "zhou")) 
            return notify_fail("��Ҫ����������\n");
        if( arg =="zhou" || arg=="boat"){
        if( me->query_skill("dodge" ,1) < 100)
            return notify_fail("��ֻ�����������ģ�ƾ���ڵ��Ṧ����Ծ��Զ����С�ۡ�\n");
        ob = deep_inventory(me);
        i = sizeof(ob);
        while (i--)
        if (ob[i]->is_character())
            return notify_fail("�����ϱ���һ���ˣ������޷����ɵ�Ծ��Զ����С�ۡ�\n");    
        tell_object(me,"�����˿�����������С����������ȥ��\n");
        tell_room(environment(me), me->name() + "������С����������ȥ��\n", ({ me }));
        room->add("ppl", 1);
        me->delete_temp("jqg");
        me->move(__DIR__"boat");
        tell_object(me,"�������������ȵ�վ����С��֮�ϡ�\n");
        return 1;
        }
}
