// ��������� /ADDED BY KEINXIN

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"2008����II�´������"NOR, ({"dalibao", "bao", "libao"}));
	set_weight(10);
set("no_drop", 1);
set("no_put", 1);
set("treasure",1);
    set("no_bug", 1);
    set("no_steal", 1);
    set("no_get", 1);
    set("value", 0);
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);

	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
set("no_drop", 1);
set("no_put", 1);
    set("no_get", 1);
    set("no_give", 0);
    set("value", 0);
		set("long", "һ���ô��������ɵ�"+HIY"�����"NOR+"�����˺�����ʦ��Դ�ҵ����ף������򿪿���(opengift)��\n");
		set("unit", "��");
	}
}
  void init()
{
  add_action("do_open","opengift");
}
int do_open()
{
	int exp,pot,score,i;
	object me = this_player();
object ob;
object gem;
        exp = 188888+random(388888);
if ((int)me->query("combat_exp")<=1000000 && !me->query("4zhuan") && !me->query("5zhuan") )
	{
        exp = 188888+random(588888);
}
        pot = exp/2;
        score = exp/8;
        if (score > 2000) score=2000;
        	
  if(me->query("liwuopen/1")>0)
  {
message_vision("����$N���Ƿ������Ѿ���������!\n", this_player());
	destruct(this_object());
   return 1;
  }
	me->set("liwuopen/1",1);
	this_player()->add("combat_exp",exp);
	this_player()->add("potential",pot);
        this_player()->add("score", score);
        this_player()->add("max_neili", 380);
	this_player()->start_busy(50);
	message_vision(HIY"$N���˴������С�����������꽣�ģ��η磬YQH��YAODM��ЦĪ�ʴ��Ž������ˣ�\n"NOR, this_player());
tell_object(me,HIY"��С������Ĵ���������Ų��õĻ𻨣�С�����������꽣�ģ��η磬YQH��YAODM��ЦĪ�ʴ��Ž������ˡ�\n"NOR);
tell_object(me,HIY" ����II�´����֣� ��ҽ��տ���!!        \n"NOR);
        tell_object(me,HIY"                                                           \n"NOR);
//	tell_object(me,HIY"���Ǹ����������ƵĽ���������Ե�������ȡ�����һ����ף�µ�һ��ĵ�����\n");
//	tell_object(me,BLINK"������ʦ���л�����´�������ǣ���л����ͬ�����߹��������ߣ�ϣ�������µ�һ���м���֧�ֺ��󷡡�\n"+
//	                    "ף�����µ�һ����һ����˳�����¿��֣��������⣡\n"NOR);                    
	tell_object(me,HIR"�㱻�����ˣ��ܶ�ܶ�����!! ^0^ \n" +
             chinese_number(exp) + "��ʵս����\n"+
             chinese_number(pot) + "��Ǳ��\n"NOR);
        message_vision(HIR"$N�����"+chinese_number(exp)+"�㾭��,"+chinese_number(pot)+"��Ǳ��!"+chinese_number(score)+"�㽭������!\n"NOR, this_player());
        message_vision(HIR"$N�����380����������!\n"NOR, this_player());
if (me->query("weapon/lv") &&
(int)me->query("weapon/lv",1)<100)
{
  me->add("weapon/lv",5);
if (me->query("weapon/lv",1)>100)
me->set("weapon/lv",100);
message_vision(HIW"$N�����������ȼ����������ˣ����µ�½����Ч!!\n"NOR, this_player());
}
if (me->query("jia/lv")&&
me->query("jia/lv",1)<150)
{
  me->add("jia/lv",5);
if (me->query("jia/lv",1)>150)
me->set("jia/lv",150);
message_vision(HIW"$N��������µȼ����������ˣ����µ�½����Ч!!\n"NOR, this_player());
}

if (random(12)==1)
{
me->delete("szj/failed");
message_vision(HIG"$N�ٴλ���ƽ����վ��Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==2)
{
me->delete("jiuyin/shang-failed");
message_vision(HIG"$N�ٴλ�ý�����ϲ�Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==3)
{
me->delete("jiuyin/xia-failed");
message_vision(HIG"$N�ٴλ�ý�����²�Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==4)
{
me->delete("zhou/jieyi");
me->delete("zhou/fail");
me->delete("zhou/failed");
message_vision(HIG"$N�ٴλ�ý�˫�ֻ����Ļ��ᣡ\n"NOR, this_player());
}
else if (random(12)==5)
{
me->delete("jiuyin/gumu-failed");
message_vision(HIG"$N�ٴλ�ý������Ĺ�Ļ��ᣡ\n"NOR, this_player());
}	
else if (random(12)==6)
{
me->set("betrayer",0);
message_vision(HIG"$N����ʦ�������㣡\n"NOR, this_player());
}


me->delete("last_getzhen");
message_vision(HIW"$N�ٴλ��������Ļ��ᣡ\n"NOR, this_player());
if (this_player()->query("kar") <20)
{
this_player()->set("kar",20);
message_vision(HIW"$N�����츣�������ˣ�\n"NOR, this_player());
}
if (this_player()->query("per") <20)
{
this_player()->set("per",20);
message_vision(HIW"$N��������ò�����ˣ�\n"NOR, this_player());
}
if (me->query_skill("unarmed",1)<120)
{
  me->set_skill("unarmed",120);
message_vision(HIW"$N�Ļ����������ˣ�\n"NOR, this_player());
}
if (me->query_skill("parry",1)<120)
{
 me->set_skill("parry",120);
message_vision(HIW"$N�Ļ����м������ˣ�\n"NOR, this_player());
}
if (me->query_skill("dodge",1)<120)
{
  me->set_skill("dodge",120);
message_vision(HIW"$N�Ļ����Ṧ�����ˣ�\n"NOR, this_player());

}
if (me->query_skill("force",1)<120)
{
  me->set_skill("force",120);
message_vision(HIW"$N�Ļ����ڹ������ˣ�\n"NOR, this_player());
}
if (me->query_skill("literate",1)<120)
{
  me->set_skill("literate",120);
message_vision(HIW"$N�Ķ���д�������ˣ�\n"NOR, this_player());
}
i=1+random(8);
if ( me->query("4zhuan") || me->query("5zhuan") )
{
if (me->query("expmax",1) < 1)
{
me->set("expmax",i);
}
else
{
me->add("expmax",i);
}	
message_vision(HIR"$N�����"+chinese_number(i)+"��ɳ�����!\n"NOR, this_player());

}    	

	destruct(this_object());
	return 1;
}
void owner_is_killed()
{
	destruct(this_object());
}