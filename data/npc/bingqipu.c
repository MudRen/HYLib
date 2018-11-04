// bingqipu.c
// by QingP

#include <ansi.h>

inherit ITEM;

void create()
{
        string file = "/data/npc/bingqipu.o";

        set_name(HIR "����������" NOR, ({ "bingqi pu" }) );
        
        set("unit", "��");
        set("long", HIW"����һ��������Զ�Ľ��������ף���������˽����ϵĳ���������

������(reading bingqi pu)���������أ�
������(checking bingqi pu)�������Լ�������������
\n"NOR);
        set("material","paper");

        set("no_get",1);
        set("no_steal",1);
        set("no_put",1);
        set("no_drop",1);

        if( file_size(file) > 0 )
                restore_object("/data/npc/bingqipu");
        
        setup();
}

void init()
{
        add_action("do_read",({"reading"}));
        add_action("do_check",({"checking"}));
}

int do_read(string arg)
{
        object obj = this_object();

        if ( !arg || arg != "bingqi pu" )
                return notify_fail("ʲ�᣿\n");

        write(HIR"                      ����������(Bingqi pu)                   \n"
           +HIG"====================================================================\n"
           +HIR"  ��һ��  " + obj->query("data/1/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/1/player") + obj->query("data/1/id") + "\n"
           +HIG"  �ڶ���  " + obj->query("data/2/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/2/player") + obj->query("data/2/id") + "\n"
           +HIY"  ������  " + obj->query("data/3/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/3/player") + obj->query("data/3/id") + "\n"
           +HIW"  ������  " + obj->query("data/4/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/4/player") + obj->query("data/4/id") + "\n"
           +HIM"  ������  " + obj->query("data/5/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/5/player") + obj->query("data/5/id") + "\n"
           +HIC"  ������  " + obj->query("data/6/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/6/player") + obj->query("data/6/id") + "\n"
           +HIC"  ������  " + obj->query("data/7/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/7/player") + obj->query("data/7/id") + "\n"
           +HIC"  �ڰ���  " + obj->query("data/8/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/8/player") + obj->query("data/8/id") + "\n"
           +HIC"  �ھ���  " + obj->query("data/9/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/9/player") + obj->query("data/9/id") + "\n"
           +HIC"  ��ʮ��  " + obj->query("data/10/w_name") + NOR"\n         ʹ���ߣ�" + obj->query("data/10/player") + obj->query("data/10/id") + "\n"
           +HIG"====================================================================\n\n"NOR);

        return 1;
}

int do_check(string arg)
{
        int level, i, j;
        object me, obj;
        mapping pmap, temp;
        string basic_skill, advance_skill, playerd;

        me = this_player();
        obj = this_object();

        if ( !arg || arg != "bingqi pu" )
                return notify_fail("ʲ�᣿\n");

        if ( wizardp(me) )
                return notify_fail("������ʦ�����...�����˰ɣ�\n");

        if ( me->query("weapon") ) {
                switch((string)me->query("weapon/type"))
                {
                        case "��":
                        basic_skill = "sword";
                        break;
                        case "��":
                        basic_skill = "blade";
                        break;
                        case "��":
                        basic_skill = "whip";
                        break;
                        case "��":
                        basic_skill = "staff";
                        break;
                        case "��":
                        basic_skill = "club";
                        break;
                        default:
                }
        }
        else {
                pmap = me->query_skill_prepare();

                if ( sizeof(pmap) == 0) basic_skill = "unarmed";
                else if ( sizeof(pmap) == 1) basic_skill = (keys(pmap))[0];
                else if ( sizeof(pmap) == 2) {
                        if ( (keys(pmap))[0] >= (keys(pmap))[1] )
                                basic_skill = (keys(pmap))[0];
                        else basic_skill = (keys(pmap))[1];
                }
        }
        
        if ( advance_skill = me->query_skill_mapped(basic_skill) )
                level = me->query_skill(basic_skill)/2 + me->query_skill(advance_skill);
        else level = me->query_skill(basic_skill)/2;
        
        i = 10;
        while( obj->query("data/"+(string)i+"/id") != "(" + me->query("id") + ")" && i > 0 ) {
                i--;
        }

        if ( i>0 ) {
                for (j=i; j<=10; j++) {
                        obj->set("data/"+(string)j, obj->query("data/"+(string)(j+1)));
                }
        }

        if ( level > obj->query("data/10/level") ) {
                if ( !me->query("weapon/name") ) {
                        if ( basic_skill == "unarmed" || basic_skill == "cuff" )
                                obj->set("data/10/w_name", "ȭͷ");
                        else if ( basic_skill == "claw" )
                                obj->set("data/10/w_name", "��צ");
                        else if ( basic_skill == "strike" )
                                obj->set("data/10/w_name", "����");
                        else if ( basic_skill == "finger" )
                                obj->set("data/10/w_name", "��ָ");
                }
                else
                        obj->set("data/10/w_name", me->query("weapon/name"));

                obj->set("data/10/level", level);
                obj->set("data/10/id", "(" + me->query("id") + ")");
                
                playerd = RANK_D->query_rank(me) + " " + me->query("title");
                if ( me->query("nickname") )
                        playerd += "��" + me->query("nickname") + "��";
                playerd += " " + me->name();

                obj->set("data/10/player", playerd);

                for ( i=1; i<10; i++ ) {
                        for ( j=i+1; j<=10; j++ ) {
                                if ( obj->query("data/"+(string)i+"/level") < obj->query("data/"+(string)j+"/level") ) {
                                        temp = obj->query("data/"+(string)i);
                                        obj->set("data/"+(string)i, obj->query("data/"+(string)j));
                                        obj->set("data/"+(string)j, temp);
                                }
                        }
                }

                i = 1;
                while( obj->query("data/"+(string)i+"/id") != "(" + me->query("id") + ")" ) {
                        i++;
                }
                message("vision", HIG"һ������Ȼ��ס" + me->name() + "���⻷��" + me->name() + "����ͣ��Ƭ�̺���ʧ�ˡ�\n
���ţ����лص���һ��������" + me->name() + "˵����"NOR + HIY"��ϲ����ı������ڽ���������"+chinese_number(i)+"��\n"NOR, environment(me), me);

                tell_object(me, HIG"һ������Ȼ��ס�㣬�⻷��������ͣ��Ƭ�̺���ʧ�ˡ�\n
���ţ���������һ������˵����"NOR + HIY"��ϲ����ı������ڽ���������"+chinese_number(i)+"��\n"NOR);
        }
        else {
                return notify_fail(HIW"ƾ�����ڵ�ʵ�������ܹ���������ס�\n"NOR);
        }
        
        save_object("/data/npc/bingqipu");

        return 1;
}

