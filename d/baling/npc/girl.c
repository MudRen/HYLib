#include <ansi.h>
inherit NPC;
int do_kiss(string arg);
int do_sleep(string arg);
void create()
{
   set_name("�Һ�",({ "tao hong","tao","hong" }) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "���ǰٻ�Է�Ĺ����Һ졣\n");
       
   set("combat_exp", 5000);
   set("str", 10);
   set("per", 28);
   set("attitude", "friendly");
   set("chat_chance",50);
   set("chat_msg",({
    "�Һ�΢΢Ц����˭ϲ���ң��������ף�qin tao���Ұ���\n",
    "�Һ�Ц��������㹻˧���ҿ�����Ѻ���˯����shuijiao tao���ģ�\n",
   }));

   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
  add_action("do_kiss","qin");
  add_action("do_sleep","shuijiao");
}
//this is a joke. :-)
int do_kiss(string arg)
{
  object me,ob;string str;
  me=this_player();
  if(!arg)
  return notify_fail("��ſ�ڵ��ϣ������Һ�Ľ�һ�¡�\n");
  if(!objectp(ob=present(arg,environment(me))))
  return notify_fail("������������𣿣�\n");
  if(ob!=this_object())
  return notify_fail("�Һ캰�����٣����ʲô�أ���\n");
  if(me->query("gender")=="Ů��")
  return notify_fail("�Һ�һЦ�����Ҵ�����ˣ�\n");
  if(me->query("jing")<200)
  return notify_fail("�Һ�Ц�����������ӣ�ûʲô���񣬵Ȼ�ɣ�\n");
  if(me->is_busy())
  return notify_fail("�Һ�һЦ���㻹��ЪЪ�ɣ�����̰�İ���\n");
  if(me->is_fighting())
  return notify_fail("�Һ����Ա�һ�����㻹���ȴ��̰ɣ�\n");
  if(me->query_per()<10)
  return notify_fail("�Һ�һ��ü���㳤�úö��İ�������Զ�㣡\n");
  if(me->query_per()<20)
  return notify_fail("�Һ�΢΢һ��ü��������ò���㻹���߰ɣ�\n");
  if(me->query_per()<26)
  str="�Һ쳯$N΢΢һЦ��"+RANK_D->query_respect(me)+",��û�����";
  if(me->query_per()<31)
  str="�Һ�����΢΢һ�죬��$N������"+RANK_D->query_respect(me)+",�㻵���㻵��\n";
  else str="�Һ�һ�����Σ��ߴ��ض�$N˵:����ʶ"+RANK_D->query_respect(me)+"�������ˣ����ҵĸ�����\n";
  message_vision(str,me);
  message_vision("$N���������$n��$N����������һ�ڡ�\n",ob,me);
  me->add("jing",-200);
  me->start_busy(2);
  return 1;
}

int do_sleep(string arg)
{
  object me,ob;string str;
  me=this_player();
  if(!arg)
  return notify_fail("��ſ�ڵ��ϣ������Һ�Ľ�һ�¡�\n");
  if(!objectp(ob=present(arg,environment(me))))
  return notify_fail("������������𣿣�\n");
  if(ob!=this_object())
  return notify_fail("�Һ캰�����٣����ʲô�أ���\n");
  if(me->query("gender")=="Ů��")
  return notify_fail("�Һ�һЦ�����Ҵ�����ˣ�\n");
  if(me->query("jing")<200||me->query("qi")<200)
  return notify_fail("�Һ�Ц�����������ӣ�ûʲô���񣬵Ȼ�ɣ�\n");
  if(me->is_busy())
  return notify_fail("�Һ�һЦ���㻹��ЪЪ�ɣ�����̰�İ���\n");
  if(me->is_fighting())
  return notify_fail("�Һ����Ա�һ�����㻹���ȴ��̰ɣ�\n");
  if(me->query_per()<10)
  return notify_fail("�Һ�һ��ü���㳤�úö��İ�������Զ�㣡\n");
  if(me->query_per()<20)
  return notify_fail("�Һ�΢΢һ��ü��������ò���㻹���߰ɣ�\n");
  if(MONEY_D->player_pay(me,5000)==0||
     MONEY_D->player_pay(me,5000)==2)
     return notify_fail("ûǮ��ûǮ����ʲô�����ɣ���\n");
  if(me->query_per()<26)
  str="�Һ쳯$N΢΢һЦ��"+RANK_D->query_respect(me)+",��û�����";
  if(me->query_per()<31)
  str="�Һ�����΢΢һ�죬��$N������"+RANK_D->query_respect(me)+",�㻵���㻵��\n";
  else str="�Һ�һ�����Σ��ߴ��ض�$N˵:����ʶ"+RANK_D->query_respect(me)+"�������ˣ����ҵĸ�����\n";
  message_vision(str,me);
  message_vision(CYN"$nӵ����$N������$Nһ��������ǣ�\n"+
                "$N������$n�Ļ�����к������������Ͻ������ޣ�\n"NOR,me,ob);
  call_out("step2",2,me,ob);
        return 1;
}

int step2(object me, object who)
{
        if(me->query("gender") == "����" ) 
            message_vision(YEL"$N�����ر�ס$n�������˵�����һ��������������һ�����£���\n"NOR,me,who);
        else
            message_vision(YEL"$N�����ر�ס$n�������˵�����һ��������������һ�����£���\n"NOR,who,me);

        call_out("remove_cloth",1,me);
        call_out("remove_cloth",1,who);
        call_out("step3",3,me,who);
        return 1;
}

int step3(object me, object who)
{
        message_vision(MAG"$N��$n�������Ҹ��ĺ������������������������\n"NOR,me,who);
        call_out("step4",2,me,who);
        return 1;
}

int step4(object me, object who)
{
        if(me->query_condition("xxx"))
                me->clear_condition("xxx");
        if(who->query_condition("xxx"))
                who->clear_condition("xxx");

        me->receive_damage("jing",me->query("max_jing")/2);
        me->receive_damage("qi",me->query("max_qi")/2);

        who->receive_damage("jing",who->query("max_jing")/2);
        who->receive_damage("qi",who->query("max_qi")/2);
       message_vision(HIW"����һ���ָֻ���ƽ����\n"NOR,me,who);
       
        return 1;
}

int remove_cloth(object me)
{
        object *inv;
        string str;
        int i;
        // remove all staff before sleepping :P
        inv = all_inventory(me);
        for(i=0; i < sizeof(inv); i++ ) {
            if( inv[i]->query("equipped") == "worn" ) {
                if( inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("remove_msg")) )
                        switch(inv[i]->query("armor_type")) {
                                case "cloth":
                                case "armor":
                                case "surcoat":
                                case "boots":
                                        str = YEL "$N��$n����������\n" NOR;
                                        break;
                                case "bandage":
                                        str = YEL "$N��$n���˿ڴ�����������\n" NOR;
                                        break;
                                default:
                                        str = YEL "$Nж��$n��װ����\n" NOR;
                        }
                message_vision(str, me, inv[i]);
                }
            } else if ( inv[i]->query("equipped") == "wielded" ) {
                if(inv[i]->unequip() ) {
                    if( !stringp(str = inv[i]->query("unwield_msg") )) 
                        str = YEL "$N�������е�$n��\n" NOR;
                message_vision(str, me, inv[i]);
                }
            }
        }
}
