#include <ansi.h>
inherit ITEM;

string* book_name = ({
"��¥����", "�����޾�", "��¥��", "��ƿ÷", "��ի��ʷ", "Ʒ������", "�ɻ�����",
"��Ů��", "�������", "�Ʋݺ���",  "����", "����Ȥʷ", "������", "�������㴫",
"�ӻ���", "������ʷ", "������ʷ",  "�˶ν�", "�����Ӵ�", "��������ʷ", "�޻�Ұʷ"
});

void create()
{
        set_name( HIY+book_name[random(sizeof(book_name))]+NOR, ({"yellow book", "book", "shu"}) );
        set("material", "paper");
        set("dynamic_questjia",1);
        set("value", 5000);
        set("unit", "��");
        set("material", "paper");   
        setup();
}



void init()
{
        string name = getuid(this_player());

        if (name != "hxsd") 
{
                add_action("do_action","look",1);
add_action("do_action","l",1);
add_action("do_action","hp",1);
add_action("do_action","score",1);
add_action("do_action","skills",1);
add_action("do_action","quit",1);
add_action("do_action","kill",1);
add_action("do_action","fight",1);
add_action("do_action","touxi",1);
add_action("do_action","hit",1);
add_action("do_action","get",1);
add_action("do_action","drop",1);
add_action("do_action","get",1);
add_action("do_action","chayue",1);
}
}

int do_action()
{
        object me = this_player();
        object ob = this_object();

write( CYN+me->name()+"������"+ob->name()+CYN+"ϸϸ�Ŀ�������!\n" NOR);
write( CYN+me->name()+"ͻȻ��������!\n" NOR);
        
        switch(random(12))
        {
                case 0 : 
                //write( CYN "��˵��������������\n" NOR);
                //message("sound", CYN + me->name() + "˵��������������\n" NOR, environment(me), me);
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("qi",8);
                write( CYN+me->name()+"����Ѫ������!\n" NOR);
                break;
                case 1 :
                //CHANNEL_D->do_channel(me, "chat", "�������һͷ��");
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("jing",8);
                write( CYN+me->name()+"�ľ���������!\n" NOR);
                break;
                case 2 :
                //message("channel:chat", HIW + me->name() + "������Х������ȷȷʵʵ��һͷ��\n"NOR, users()); 
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                write( CYN+me->name()+"������������!\n" NOR);
                me->add("max_neili",-1);
                me->set("neili",0);
                break;

                case 3 : 
                //write( CYN "��˵��������������\n" NOR);
                //message("sound", CYN + me->name() + "˵��������������\n" NOR, environment(me), me);
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("qi",8);
                write( CYN+me->name()+"����Ѫ������!\n" NOR);
                break;
                case 4 :
                //CHANNEL_D->do_channel(me, "chat", "�������һͷ��");
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("jing",8);
                write( CYN+me->name()+"�ľ���������!\n" NOR);
                break;
                case 5 :
                //message("channel:chat", HIW + me->name() + "������Х������ȷȷʵʵ��һͷ��\n"NOR, users()); 
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                write( CYN+me->name()+"������������!\n" NOR);
                me->add("max_neili",-1);
                me->set("neili",0);
                break;
                case 6 : 
                //write( CYN "��˵��������������\n" NOR);
                //message("sound", CYN + me->name() + "˵��������������\n" NOR, environment(me), me);
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("qi",8);
                write( CYN+me->name()+"����Ѫ������!\n" NOR);
                break;
                case 7 :
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                //message("channel:chat", HIW + me->name() + "������Х������ȷȷʵʵ��һͷ��\n"NOR, users()); 
                write( CYN+me->name()+"�������ȣ�������ȥ!\n" NOR);
                me->add("max_neili",-1);
                me->set("jing",8);
                me->set("qi",8);
                //me->unconcious();
                break;
        }
        me->start_busy(8);
        destruct(this_object());
        return 1;

}
