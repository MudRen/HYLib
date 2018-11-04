// master.c

inherit NPC;

#include <ansi.h>
mapping *data=({
(["id":"zuizui","title":"����֮��","name":"׺׺",]),
(["id":"zhword","title":"��Զ��Ư����","name":"����",]),
(["id":"danyingzi","title":"���������","name":"������",]),
(["id":"fox","title":"ᰵ�ð����","name":"����",]),
(["id":"cash","title":"�׵�̽���","name":"��Ʊ",]),
(["id":"fen","title":"���޶���","name":"����",]),
(["id":"lting","title":"����Ůɮ��","name":"�L���滨","sex":1,]),
(["id":"shazi","title":"��֮ͫ��","name":"���",]),
(["id":"hotwing","title":"ħ��ս��","name":"������ʹ",]),
(["id":"lavender","title":"ħ��֮��ò","name":"޹�²�","sex":1,]),
(["id":"bakangel","title":"ʥ֮Ů��ʿ","name":"����ʹ","sex":1,]),
(["id":"rains","title":"�缲����","name":"СС��ʿ",]),
(["id":"guipu","title":"�������","name":"����",]),
(["id":"flyt","title":"ͫ��Ů��ʿ","name":"����","sex":1,]),
(["id":"qing","title":"����֮��ò","name":"����Ũ","sex":1,]),
(["id":"sos","title":"����֮ӥ","name":"�ɷɷɷɻ�",]),
(["id":"dings","title":"��֮����","name":"Ѽ��",]),
(["id":"damenly","title":"�������","name":"ȱ�¾�ʿ",]),
(["id":"Qlbl","title":"�ɫ���","name":"��竹���",]),
(["id":"xbd","title":"ħ֮̽����","name":"С����",]),
(["id":"game","title":"��֮����","name":"��Ϸ",]),
(["id":"amei","title":"����֮��","name":"ǧɽĺѩ","sex":1,]),
(["id":"zbabla","title":"����֮��","name":"��ң����",]),
(["id":"lunar","title":"��֮Ů��","name":"ѩ÷","sex":1,]),
(["id":"yoyo","title":"����ħ��֮��","name":"����",]),
(["id":"snowfly","title":"��������","name":"ѩ��Ʈ","sex":1,]),
(["id":"wto","title":"��ħ�����","name":"������ŷ",]),
(["id":"hadis","title":"����֮��","name":"����˹",]),
(["id":"angel","title":"���ߵ��ػ���","name":"糴嵶��",]),
(["id":"zohu","title":"���صĹ��","name":"����",]),
(["id":"dfei","title":"�������","name":"���",]),
(["id":"bakangel","title":"��ħ�Ĵ���Ů","name":"����ʹ","sex":1,]),
(["id":"woodtian","title":"�������","name":"�Ұ�����Ů",]),
(["id":"kjhojin","title":"��ħ������","name":"ˮ���","sex":1,]),
(["id":"thill","title":"�����ʹ��","name":"������",]),
(["id":"dido","title":"ʥͫ","name":"������",]),
(["id":"cold","title":"��ʹ����","name":"����",]),
(["id":"scan","title":"��һ���׸���","name":"��Ӣ����",]),
(["id":"lubinh","title":"�������Ĳ�","name":"С����",]),
(["id":"lightning","title":"��ħ��С͵","name":"����",]),
(["id":"xiaomei","title":"Ů���΢Ц","name":"С��","sex":1,]),
(["id":"dldi","title":"��ɫצ��","name":"�����幤",]),
(["id":"mafan","title":"����ָ֮","name":"�鷳",]),
(["id":"hailoo","title":"����ħŮ","name":"��������","sex":1,]),
(["id":"bingxueer","title":"ʥħŮ","name":"��ѩ��","sex":1,]),
(["id":"caree","title":"����Ů��","name":"��������","sex":1,]),
(["id":"damenl","title":"�ɫ��ʿ","name":"��Ǯ�뷢��",]),
(["id":"xiaotian","title":"���з������ë","name":"Х��",]),
(["id":"waaas","title":"��Ⱦħ��","name":"�ض�","sex":1,]),
(["id":"dbabla","title":"������","name":"��а",]),
(["id":"lyf","title":"��Ӱ��Ů","name":"������","sex":1,]),
(["id":"loveyqh","title":"ʥ֮ħ��ʦ","name":"ˮ��",]),
(["id":"lovefox","title":"��Ů��","name":"����","sex":1,]),
(["id":"linda","title":"��֮Ů��ʿ","name":"�׾���","sex":1,]),
(["id":"lindy","title":"����֮��","name":"Ľ����","sex":1,]),
(["id":"lexy","title":"Ư������Ҷ","name":"����ң",]),
(["id":"laiyinhate","title":"��������","name":"�������",]),
(["id":"yzx","title":"��Զ������","name":"��������",]),
(["id":"xnh","title":"�컢","name":"����",]),
(["id":"xjhjin","title":"����Ů��","name":"����","sex":1,]),
(["id":"xiaoxuan","title":"������΢Ц","name":"������",]),
(["id":"xdb","title":"����սʿ","name":"ѩ����",]),
(["id":"wumi","title":"��֮��","name":"����",]),
(["id":"wukong","title":"����սʿ","name":"�����ʥ",]),
(["id":"wishluck","title":"����֮��","name":"С����","sex":1,]),
(["id":"winco","title":"��������","name":"�Ʒ�",]),
(["id":"wanxia","title":"��ն����","name":"��ϼ","sex":1,]),
(["id":"wanghu","title":"��ᰵ�����","name":"�������",]),
(["id":"waaa","title":"��������","name":"����",]),
(["id":"myth","title":"�ǻݵ�������","name":"Ľ�ݲ�",]),
(["id":"vov","title":"��·�Ĵǵ�","name":"����",]),
(["id":"tyywl","title":"����֮��","name":"��ҰԴ����",]),
(["id":"ttss","title":"��װ����","name":"������","sex":1,]),
(["id":"tianjun","title":"�ž�֮����","name":"����",]),
(["id":"tcl","title":"а��","name":"����",]),
(["id":"taotao","title":"��ħ֮����","name":"OhMyGod",]),
(["id":"sug","title":"��ϸ��ָ��","name":"�����","sex":1,]),
(["id":"sprite","title":"����ħ��","name":"С����",]),
(["id":"sony","title":"�ڸּ���","name":"Ե��",]),
(["id":"snq","title":"��ʵ��̽����","name":"СС",]),
(["id":"snow","title":"������֮Դ","name":"������ѩ","sex":1,]),
(["id":"smj","title":"������֮��","name":"������",]),
(["id":"smile","title":"����֮��","name":"����",]),
(["id":"sjmoxj","title":"�������","name":"����ʫ��",]),
(["id":"siren","title":"а��ʹ��","name":"���",]),
(["id":"shuanger","title":"ˮӳ֮��","name":"����˪","sex":1,]),
(["id":"shanc","title":"���ɵ���Ů","name":"����","sex":1,]),
(["id":"sgy","title":"��ʹͽ","name":"С��",]),
(["id":"scare","title":"������������","name":"Ц����",]),
(["id":"rui","title":"����֮ħ�ٹ���","name":"��ѩƮ��","sex":1,]),
(["id":"quanjia","title":"����Ů","name":"Ȫ��","sex":1,]),
(["id":"qkry","title":"�����","name":"Ǭ������",]),
(["id":"qiuqiu","title":"��ս�پ�","name":"����",]),
(["id":"qazqaz","title":"����ʿ","name":"������",]),
(["id":"pxf","title":"����ı���","name":"ľ��",]),
(["id":"pcgame","title":"����֮ս��","name":"����",]),
(["id":"papaya","title":"�ƻ���","name":"����",]),
(["id":"orange","title":"����Ů��","name":"����","sex":1,]),
(["id":"ooo","title":"�����Ͻ�","name":"���֮��",]),
(["id":"only","title":"�����Ĳ��ܶ�ʿ","name":"�����о�",]),
(["id":"nvnv","title":"��֮��ʿ","name":"����",]),
(["id":"npc","title":"���Ĵ�����","name":"С����","sex":1,]),
(["id":"name","title":"аսʿ","name":"ֱ����",]),
(["id":"mzlm","title":"�Ҹ�ʹ��","name":"����",]),
(["id":"marine","title":"������������","name":"����Ź�",]),
(["id":"means","title":"����������","name":"��˼",]),
(["id":"miean","title":"�޹�Ե�ָ��","name":"����",]),
(["id":"mingyang","title":"��ħ��ʹ��","name":"����",]),
(["id":"mini","title":"��ɫħ��","name":"����",]),
(["id":"mmm","title":"����֮ӥ","name":"�Ž�һ��",]),
(["id":"mrf","title":"���ڽֵ�֧����","name":"Ľ�ݷ�",]),
(["id":"mryh","title":"�ž��İ�ɱ��","name":"�ƻ�",]),
(["id":"myboy","title":"�����","name":"�������",]),
(["id":"mygirl","title":"�ڹ�֩��","name":"����","sex":1,]),
(["id":"lang","title":"��ħ���","name":"�˷���",]),
(["id":"langer","title":"����֮ͷ��","name":"����",]),
(["id":"legs","title":"ħ��Ů��ʿ","name":"��������","sex":1,]),
(["id":"lbxx","title":"��ħ��ʹ��","name":"����С��",]),
(["id":"lengxin","title":"��֮��ʿ","name":"����",]),
(["id":"ling","title":"��ɫŮ��ʦ","name":"���","sex":1,]),
(["id":"ljgbook","title":"��������","name":"����","sex":1,]),
(["id":"lkdd","title":"����սʿ","name":"�ٱ��Ǿ�",]),
(["id":"kara","title":"�û�֮Ůħ��ʦ","name":"����","sex":1,]),
(["id":"keeny","title":"������","name":"����",]),
(["id":"keyboard","title":"��֮����","name":"����",]),
(["id":"kgb","title":"��Զ��(ͨ����)","name":"����С��",]),
(["id":"killman","title":"�ɻ�С��","name":"�����Ǯ��",]),
(["id":"jad","title":"���ȵ���","name":"����",]),
(["id":"jianxin","title":"������ʦ","name":"��̫",]),
(["id":"jxy","title":"����֮����","name":"Ф��",]),
(["id":"icefox","title":"���ߵ�����","name":"����",]),
(["id":"hadis","title":"�������","name":"����˹",]),
(["id":"hechuan","title":"��ɫ����","name":"��Ӣ��",]),
(["id":"hehaia","title":"����ʹ��","name":"�κ���",]),
(["id":"himura","title":"���鷨ʦ","name":"����",]),
(["id":"honda","title":"���˽�ʿ","name":"����",]),
(["id":"huakai","title":"С����","name":"���仨��",]),
(["id":"hylijun","title":"������","name":"����è",]),
(["id":"hxt","title":"����սʿ","name":"��ֽһ��",]),
(["id":"huihui","title":"����ħ��ʹ","name":"��Ľ",]),
(["id":"gameking","title":"�����ʿ","name":"��Ϸ֮��",]),
(["id":"gaoc","title":"���鳤��","name":"�߲�",]),
(["id":"gmxy","title":"����ɱ��","name":"����",]),
(["id":"grape","title":"�ڰ�����","name":"�̶���",]),
(["id":"green","title":"ɱ�ֹ���ʹ��","name":"��Ҷ��",]),
(["id":"fadai","title":"��Ԫ��ʹ��","name":"����",]),
(["id":"fall","title":"ʥ��֮����","name":"������","sex":1,]),
(["id":"fff","title":"��Ԫ��ʹ��","name":"����",]),
(["id":"ffs","title":"��Ԫ��ʹ��","name":"��а",]),
(["id":"fgy","title":"ˮԪ��ʹ��","name":"������",]),
(["id":"flower","title":"��֮Ů��","name":"������","sex":1,]),
(["id":"foryou","title":"����Ů����","name":"��ʫ","sex":1,]),
(["id":"foxzzz","title":"�ڰ�����Ů","name":"ѩ��","sex":1,]),
(["id":"frfr","title":"ħ����ʿ","name":"����",]),
(["id":"ftoiloveyou","title":"��֮��ʦ","name":"ѩ����ʥ",]),
(["id":"fury","title":"��ɫ����ʦ","name":"��ƽ��",]),
(["id":"fusheng","title":"�ƻ���֮��ʦ","name":"��.����",]),
(["id":"eddie","title":"����֮ͫ","name":"������","sex":1,]),
(["id":"ehuan","title":"ħ��Ůսʿ","name":"����","sex":1,]),
(["id":"enjoy","title":"��������","name":"����",]),
(["id":"eric","title":"ʥ��ʿ","name":"����",]),
(["id":"dairun","title":"ħ��ʿ","name":"����",]),
(["id":"dali","title":"����ɱ��","name":"����",]),
(["id":"datank","title":"�ٹ�֮��ʿ","name":"��̹��",]),
(["id":"dhxy","title":"������ʿ","name":"������",]),
(["id":"digu","title":"��֮����","name":"ͯ��ϱ",]),
(["id":"dldi","title":"��ʿ��","name":"�����幤",]),
(["id":"dodo","title":"��ʿͳʦ","name":"ûƷ����",]),
(["id":"donkey","title":"������ʿ","name":"¿��",]),
(["id":"duly","title":"����ʿ","name":"����",]),
(["id":"caiyi","title":"��Ѫ��Ů����","name":"����","sex":1,]),
(["id":"camin","title":"�޳ܺ�����","name":"Ц��",]),
(["id":"chaosheng","title":"ʥ��֮Ұ����","name":"����",]),
(["id":"cloud","title":"Ұ����֮��","name":"����",]),
(["id":"com","title":"���ǵ�Ұ����","name":"���",]),
(["id":"cutlove","title":"Ұ���˷�ʦ","name":"�ᵶ",]),
(["id":"baggio","title":"Ұ��֮ħ��ʹ","name":"��ԯ��",]),
(["id":"baishi","title":"��Ѩ����֮ĸ","name":"������","sex":1,]),
(["id":"banana","title":"�������","name":"�㽶",]),
(["id":"baoer","title":"����","name":"�ֱ���",]),
(["id":"battlee","title":"ʳ��ħŮ��","name":"Ѧ��","sex":1,]),
(["id":"bear","title":"ľ����","name":"Ц��",]),
(["id":"bee","title":"��Ůţͷ��","name":"Ů����","sex":1,]),
(["id":"bihu","title":"������","name":"�ڻ�",]),
(["id":"biluo","title":"��ɫ֮����","name":"����������","sex":1,]),
(["id":"bird","title":"�����˹���","name":"����","sex":1,]),
(["id":"bingxueer","title":"�ɰ���ʳʬ��","name":"��ѩ��","sex":1,]),
(["id":"bmr","title":"����֮���","name":"ѩ��","sex":1,]),
(["id":"budai","title":"Ԫ����","name":"������ȥ",]),
(["id":"bullet","title":"ħ����ʿ","name":"С��",]),
(["id":"admire","title":"ʳ��������","name":"����",]),
(["id":"aka","title":"�ڰ�����","name":"����",]),
(["id":"akan","title":"ħ������","name":"Ī������",]),
(["id":"amejio","title":"����ħ����Ů","name":"���","sex":1,]),
(["id":"amy","title":"��ҹ֮Ůɱ��","name":"����","sex":1,]),
(["id":"ant","title":"����֮��ħ��ʿ","name":"����","sex":1,]),
(["id":"anran","title":"ħ��˾��","name":"������Ȼ",]),
(["id":"aoe","title":"ħ�峤","name":"�ɰ�",]),
(["id":"axax","title":"ħ��ʹָ�ӹ�","name":"����",])
});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

void create()
{
	mapping npc;
	string sex;
	npc=data[random(sizeof(data))];
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);

if (sex)
set("gender", "Ů��" );
else set("gender", "����" );
set("pubmaster",1);
        set("age", 34);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
        set("agi",25);
      set("dex",80);
      set("con",80);
     set("str" ,80);
set("dex",80);
set("int",80);
set("per",80);
set("kar",80);       
    set("age", 22+random(40));
     set("chat_chance", 4);
        set("chat_msg", ({
                (: random_move :),
           }) );
	set("attitude","friendly");
set("pubmaster",1);
        set("max_neili", 35000);
        set("neili", 35000);
        set("jing",5000+random(10000));
        set("max_jing",5000+random(10000));
set("eff_jing",5000+random(10000));
        set("qi",5000+random(10000));
        set("max_qi",5000+random(10000));
set("eff_qi",5000+random(10000));
 
        set_skill("parry", 320);
        set_skill("dodge", 320);
        set_skill("force", 300);
        set_skill("literate", 300);
	set_skill("sword", 300);
	set_skill("unarmed",380);
	set("combat_exp",20000000+random(9000000));
        set_skill("force",400+random(200));
	set_skill("unarmed",400+random(200));
	set_skill("sword",400+random(200));
	set_skill("club",400+random(200));
	set_skill("whip",400+random(200));
	set_skill("throwing",400+random(200));
	set_skill("parry",400+random(200));
set_skill("spells",300+random(300));
      set_skill("magic-unarmed", 300+random(300));
      set_skill("magic-sword", 300+random(300));
      set_skill("magic-fire", 300+random(300));
      set_skill("magic-water", 300+random(300));
      map_skill("sword", "magic-sword");
      map_skill("unarmed", "magic-unarmed");
      map_skill("parry", "magic-unarmed");
	set("magicset",1);
       set("zhuanbest",1);
        set("no_get",1);
set("vendetta/authority",1);
if (random(2)==0)
{
map_skill("spells", "magic-water");
	set("magicgift",2);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               (: perform_action, "spells.door" :),
               (: perform_action, "spells.iceball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.crystal" :),
               (: perform_action, "spells.icebolt" :),
               (: perform_action, "spells.storm" :),                                                            
               (: perform_action, "spells.summon" :),                                                            
               (: perform_action, "spells.zeroring" :),                                                            
        }) );
}
else {
map_skill("spells", "magic-fire");
	set("magicgift",1);
                set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
               (: perform_action, "spells.light" :),
               (: perform_action, "spells.fireball" :),
               (: perform_action, "spells.resistance" :),
               (: perform_action, "spells.immolation" :),
               (: perform_action, "spells.firebolt" :),
               (: perform_action, "spells.meteor" :),                                                            
               (: perform_action, "spells.incinerate" :),                                                                                                                     
        }) );
}
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/armor", 400);
        set_temp("apply/damage", 300);
        setup();
carry_object(__DIR__"obj/sword")->wield();
carry_object(__DIR__"obj/cloth")->wear();
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        int i;
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;        
              me->add("score",1);
        message_vision(RED"$N,���ض������������ˡ�\n"NOR,ob,me);
        if((int)me->query("combat_exp") < ob->query("combat_exp"))   {
        message("vision", me->name() + HIG"�ɹ�ɱ��"+ob->query("name")+",������200�����100Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",200);
        me->add("potential",100);
        me->add("score",1);
if (random(5)==0 && me->query("zhuanbest"))
{
if (random(2)==0)
{
i=(random(4)+1);
corpse=new("/clone/magic/obj/w"+i);
corpse->move(me);
message("vision", me->name() + HIG"�ҵ���"+corpse->query("name")+"��\n"NOR, me);
}
else
{
i=(random(4)+1);
corpse=new("/clone/magic/obj/s"+i);
corpse->move(me);
message("vision", me->name() + HIG"�ҵ���"+corpse->query("name")+"��\n"NOR, me);
}
}

        destruct(ob);
        }

               destruct(ob);
        return;
}
