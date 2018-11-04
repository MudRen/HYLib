#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
//inherit F_AUTOLOAD;
inherit F_DAMAGE;
//inherit F_CLEAN_UP;
inherit F_COMMAND;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);
string inputstr,verb;
int main(object me, string arg);

void create()
{

       seteuid(getuid());
       set_name(HIW"����֮��"NOR,({"xyanhu robe","xyanhurobe" }));

       if(clonep())
           set_default_object(__FILE__);
       else{
           set("unit","��");
           seteuid(geteuid());
           set("material", "cloth");
           set("armor_prop/armor", 10000);
           set("no_get",1);
           set("no_get",1);
           set("no_drop",1);
           }
       setup();
}
// ����ֱ��
void init()
{
string wiz_status;
object me;
	seteuid(geteuid());
	me = this_player(1);
	wiz_status = SECURITY_D->get_status(me);

       if( wizardp(environment()) ) {
       add_action("full","full"); 
       add_action("hun","hun");
       add_action("bx","bianxing");
       add_action("nicks","nicks");
       add_action ("whereall", "whereall");
       add_action("jiaban","jb");
       add_action("jianting","jt");
       add_action("yao","yao");
       add_action("xing","xing");
       add_action("combat_exp","exp"); 
      add_action ("skill", "skill");
       add_action ("age", "age"); 
       this_player()->set_temp("heat",1);
      }
}

// COMBAT_EXP �޸ľ���
int combat_exp(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("combat sb. exp\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("combat_exp",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("combat sb. exp\n");
}
// AGE ����
int age(string str)
{
        object me,target;
        string name;
        int level;
        me=this_player();
        if(!str) return notify_fail("age sb ���ӵ����.\n");
        if(sscanf(str,"%s %d",name,level)==2)   {
        if(!(target=present(name,environment(me))))
                return notify_fail("û��û����ô���ˡ�\n");
        target->add("mud_age",86400*level);
        target->add("age",level);
        write("�޸�"+WHT+target->query("name")+NOR+"���������"+HIR+(string)level+NOR+"�ꡣ\n",this_object());
        return 1;
        }
        else
        return notify_fail("age sb. ���ӵ���͡�\n");
}
//  SKILL �书
int skill(string str)
{
        object me;
        object target;
        string name,skills;
        int level;
        if(!str)        return notify_fail("skill ĳ�� ���� �ȼ�\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,skills,level)==3)         {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->set_skill(skills,level);
        write("�޸�"+WHT+target->query("name")+NOR"��"+YEL+to_chinese(skills)+NOR+"�书Ϊ"+HIR+(string)level+NOR"����\n",this_object());
        return 1;
        }
        else
        return notify_fail("skill ĳ�� ���� �ȼ�\n");
}

// BAN �ٰ�
int jiaban(string str)
{
        object ob1;
        string st1,st2;
        if (!str || str=="") return notify_fail ("��Ҫװ��˭��˵����\n");
        if (sscanf( str,"%s say %s",st1,st2)!=2 )
               return notify_fail ("ban <id> say <message>\n");
        if (!ob1=present(st1,environment(this_player())))
               return notify_fail("�������û��"+st1+"�ɡ�\n");
        message("sound", NOR+ ob1->name() + "˵����" + HIG +  st2 + "\n" NOR,
        environment(ob1), ob1);
        return 1;
}
// JIANTING ����
int jianting(string arg)
{
        object me=this_player();
        object ob;
        if( !arg ) {
                if( objectp(ob = query_snooping(me)) )
                        write(HIR "���������ڼ���" + ob->query("name") + "���յ���ѶϢ����\n" NOR);
                return 1;
        } else if( arg=="none" ) {
                snoop(me);
                write(HIG "������ֹͣ�������˵�ѶϢ��\n" NOR);
                return 1;
        }
        ob = find_player(arg);
        if(!ob) ob = find_living(arg);
        if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");
        if( wiz_level(me) < wiz_level(ob) )
                return notify_fail("��û�м���" + ob->name() + "������ѶϢ��Ȩ����\n");
        if( me==ob ) return notify_fail("���� snoop none �� jt none���������\n");
        snoop(me, ob);
        write(HIM "�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n" NOR);
        if (me->query("id")!="yesno") {
        if( userp(ob) ) log_file("SNOOP_PLAYER",
                sprintf("%s(%s) ���� %s �� %s.\n", me->name(1), geteuid(me), ob->name(1),
                        ctime(time()) ) );
        }
        return 1;
}

// WHEREALL �鿴ĳ��
int whereall(string arg)
{
  object where, me, play;
  object *ob;
  string msg;
  int i;
  if (arg!=NULL_VALUE){
    play=LOGIN_D->find_body(arg);
    if (!play) return notify_fail("����û�����ѽ��\n");
    }
  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("������һ�������С�\n");
    msg =HIC+where->query("short")+NOR+"  -- "+WHT+file_name(where)+"\n"NOR;
    msg += where->query("long");
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s)   %15s   %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s)   %15s   %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;
}

//  XING ʹ������
int xing (string str)
{
  object who;
  if (!str) return notify_fail ("xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("û��"+str+"ѽ��\n");}
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}
// HUN ʹ�˻赹
int hun (string str)
{
  object who;
   object me;
   me=this_player();
  if (!str) return notify_fail ("����ˣ����Լ�Ū�Σ�\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("û��"+str+"ѽ��\n");}
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}
//  BX ��������
int bx(string arg)
{
  object bxid,me;
  me=this_player();
  if (arg!=NULL_VALUE){
    bxid = LOGIN_D->find_body(arg);
    if (!bxid) return notify_fail("�����Ϻ���û�����ѽ��\n");
    }
  if (arg) {
    if(arg=="hxsd") return notify_fail("����������\n");
    if(bxid->query("gender")=="Ů��") bxid->set( "gender", "����" );
    else bxid->set( "gender", "Ů��" );
    message("shout", HIM "��ҥ�ԡ�ĳ�ˣ���˵"+me->query("name")+"�ɹ��Ķ�" 
    +bxid->query("name")+"������һ�α���������\n" NOR,users());
    bxid->save();
    return 1;
  }
}
//  YAO ȡǮ
int yao (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <����Ǯ> <Ǯ������>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("����û������Ǯѽ��ҡ��ƨѽ��\n");
        if( amount < 1 )
                return notify_fail("�Ǻǣ�����û�С�\n");
        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
 message_vision( sprintf(HIY "$Nʹ�������Լ��Ŀڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n" NOR,
        chinese_number(amount),n_money->query("base_unit"),n_money->query("name")),
        this_player());return 1;
}
//  FULL ��Ѫ
int full(string str)
{
  object me;
  int max;

       if(!geteuid()) seteuid (getuid());
       if(!str)
          me=this_player();
       else{
          me=LOGIN_D->find_body(str);
       if(!me) return notify_fail ("�Բ���û���ҵ� [ "+str+" ]��\n");}
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity(); 
  me->set("water",max);
  max = me->query("max_neili");
  me->set("eff_neili",max);
  me->set("neili",max*2);
  me->clear_condition();
  message_vision( sprintf(HIY"$N��ʼ���������... ...��ɲ�Ǽ�$n��ʼ���������ˡ�\n"NOR),
                  this_player(),me);
  return 1;
}
// nicks�޸�
int nicks(string arg)
{
        string dest;
        object me;
        me = this_player();
        if( !arg ) return notify_fail("��Ҫ��˭�ã�\n");
        if(sscanf(arg,"-title %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("�������ֻ������ʦʹ�á�\n");
                return wiz_set(dest,arg,"title",1)?1:notify_fail("����ʧ�ܡ�\n");
        }
        if(sscanf(arg,"-name %s,%s",dest,arg)==2)
        {
                if(!wizardp(me))
                        return notify_fail("�������ֻ������ʦʹ�á�\n");
                return wiz_set(dest,arg,"title",1)?1:notify_fail("����ʧ�ܡ�\n");
        } 
        if(sscanf(arg,"-nick %*s")==1)
                sscanf(arg,"-nick %s",arg);
        if( strlen(replace_color(arg,0)) > 70 )
                return notify_fail("�º�̫���ˣ�������һ����һ��ġ�����һ��ġ�\n");
        return wiz_set("me",arg,"nickname",1)?1:notify_fail("����ʧ�ܡ�\n");
        write("Ok.\n");
        return 1;
}
int wiz_set(string str1,string str2,string prop,int color_flag)
{
        object ob,me;
        me=this_player(1);
        if(str1=="me")
                ob=this_player(1);
        else
                if(!objectp(ob=present(str1,environment(me))))
                        if(!objectp(ob=find_player(str1)))
                                if(!objectp(ob=find_living(str1)))
                                {
                                        tell_object(me,"���ܷ��ֲ�������("+str1+")��\n");
                                        return 0;
                                }
        if(wiz_level(me)<wiz_level(ob))
        {
                tell_object(me,"���Ȩ�޲�����\n");
                return 0;
        }
        if((prop=="title"&&wizardp(me))||prop=="nickname")
                if(str2=="cancel")
                {
                        ob->delete(prop);
                        message_vision("$N��"+prop+"������ˡ�\n",ob);
                        return 1;
                }
        str2=replace_color(str2,color_flag);
        message_vision("$N��"+prop+"���趨Ϊ:"+str2+"\n",ob);
        ob->set(prop,str2);
        return 1;
}

string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}
int query_autoload()
{
return 1;
}
