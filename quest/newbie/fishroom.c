// fishroom.c
// 4/16/2000 by lag

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
���߽�����ۣ��кö�������������ѽ����ʱ�Ĵ�����
�ܵĺ���������϶�������˭�����˴��㣬��������ææµµ��
�˷ܵ����ӣ��㻹��ʲôֵ����ԥ�ģ��Ͽ���ʰ�������ܿ�ʼ
����(diao)�ɣ�������һ����Ϣ�ҡ�
LONG );
        set("exits", ([
//                "enter" : __DIR__"xiuxi",
                "west" : "d/shaolin/hanshui1",
        ]));
        set("no_steal", 1);
        set("no_sleep", 1);
        set("no_drop", 1);
        set("no_fight", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_fish", "fish");
        add_action("do_fish", "diao");
}

int do_fish(string arg)
{

        object me;
        me = this_player();

        if (me->query("combat_exp") > 10000) {
                message_vision(HIG"����ʹ�ߵ���ӰͻȻ������һ������֮�С�\n" +
            HIR "����ʹ�߳���$N��ȣ���ȥ�����ң���ô���˻������㣬���߲���ѽ��\n\n\n"NOR,me);
                    me->move("/d/shaolin/hanshui1");
                     return 1;
                                               } else
        if ( !arg || ( arg != "��" ) ) return 
                   notify_fail("��Ҫ��ʲô��?������\n");
        else

        if (me->query("qi") < 20 )
                return notify_fail("���֧�ֲ�ס�ˣ���Ъ����ɣ�\n");
        else
                message_vision("$N����һ�ѵ�������ڴ�ʯͷ�ϵ�������������\n", me);
        if (me->is_busy())
                return notify_fail ("�㻹����װ�������˵�ɣ�\n");

                switch(random(10)) {  
                        case 0 :             
                             message_vision("$Nһ��ˣ�������һ��"+ HIR "������"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",15+random(2));
                             me->add("combat_exp",20+random(7));
                             me->add("qi",-15);
                           break;
                        case 1 :
                             message_vision("$N��һ��ˣ�������"+ CYN "һ���Ʋ�ñ"NOR +"��������������  \n",me);
                             message_vision(HIW "$N�����Ʋ�ñ���ɵķ����ˡ�  \n\n" NOR,me);
                             me->add("qi",-5);
                           break;
                        case 2 :
                             message_vision("$N��Ư�ζ���$N����һ�����͵�һ��ˣ�$N������"+ RED "һ����ɫ�ĶǶ��� \n"NOR,me);
                             message_vision(HIB "$N�����е��������������� \n\n" NOR,me);
                             me->add("qi",-7);
                           break;
                        case 3 :
                             message_vision("$Nһ��ˣ�������һ��"+ HIC "����"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",3+random(2));
                             me->add("combat_exp",9+random(7));
                             me->add("qi",-6);
                           break;
                        case 4 :
                             message_vision("$Nһ��ˣ�������һ��"+ HIG "����"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",11+random(2));
                             me->add("combat_exp",18+random(7));
                             me->add("qi",-12);
                           break;
                        case 5 :
                             message_vision("$Nһ��ˣ�������һ�����㣬��ϲ����ϲ�� \n\n",me);
                             me->add("potential",6+random(2));
                             me->add("combat_exp",9+random(7));
                             me->add("qi",-10);
                           break;
                        case 6 :
                             message_vision("$Nһ��ˣ�������һ��"+ HIB "����"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",7+random(2));
                             me->add("combat_exp",8+random(7));
                             me->add("qi",-5);
                           break;
                        case 7 :
                             message_vision("$N��һ��ˣ�������"+ WHT "һ���Ͼɵ�˯��"NOR +"�������������� \n",me);
                             message_vision(HIY"$N���ŷϾɵ�˯�����۾����̺��ˡ� \n\n"NOR,me);
                             me->add("qi",-3);
                           break;
                        case 8 :
                             message_vision("$N�͵�һ��ˣ�����̫���ˣ��߶��ˣ������ˣ���ϧ����ϧ�� \n",me);
                             message_vision(HIC "$N���ɵ����������:���ɥѡ� \n\n" NOR,me);
                             me->add("qi",-7);
                           break;
                        default :
                             message_vision("$Nһ��ˣ�������һ��"+ HIM "������"NOR +"����ϲ����ϲ�� \n\n",me);
                             me->add("potential",10+random(2));
                             me->add("combat_exp",10+random(7));
                             me->add("qi",-8);
                           break;    
                                 }         
                         me->start_busy(2);

        return 1;
}

