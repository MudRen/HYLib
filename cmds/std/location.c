// location.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *place_desc = ({
	"�͵�" ,
	"����" ,
	"���Ĺ㳡" ,
	"��ʯ���" ,
	"ɽ·" ,
	"�����"
});
int main(object me, string arg)
{
	object ob,where,env,obj;
        mapping myfam;
        string region;
	mapping fam;
	int sp, dp;
	int i, cost;
	int lvl, diff, busy_time;
	        int b1,b2;
int maxpot;	        
	seteuid(getuid());

        if ( (!(fam = me->query("family")) || fam["family_name"] != "�һ���") && !wizardp(me) )
		return notify_fail("ֻ���һ������Ӳ��ܴ�̽���˵����ڣ�\n");

	if( (lvl = (int)me->query_skill("count", 1)) < 10 )
		return notify_fail("�������������δ���죬�޷��˽���˵����ڣ�\n");


	if( ((int)me->query_skill("bibo-shengong", 1)) < 10 )
		return notify_fail("��ı����ڹ���δ���죡\n");
		
if (!environment(me))
                return notify_fail("��ҪӰ����ˣ�������һ����ĵط��ɡ�\n");
        if (environment(me)->query("sleep_room"))
                return notify_fail("��ҪӰ����ˣ�������һ����ĵط��ɡ�\n");
        if (me->is_fighting()) 
        return notify_fail("���������������!\n");
       if( environment(me)->query("no_beg") ||
       environment(me)->query("no_fight") ||
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

        if (me->is_busy()
        || me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("��������æ���ء�\n");

	if ( !arg )
		return notify_fail("��Ҫ����˭�����ڣ�\n");

        if ( present(arg, environment(me)) )
		return notify_fail("��Ҫ�������˾��ڱ��ϣ���������ɣ�\n");

	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("��Ҫ����˭�����ڣ�\n");
        if( !wizardp(me) && wizardp(ob) ) 
		return notify_fail("��Ҫ����˭�����ڣ�\n");

	if ( ob == me )
		return notify_fail("��û���᱿�ɣ�Ҫ���˸������Լ������ڣ�\n");
	if ( me->query("jing") <= 60 )		return notify_fail("������̫���ˣ��޷�ȥ�������˵����ڡ�\n");
if ( me->query("qi") <= 60 )		return notify_fail("������̫���ˣ��޷�ȥ�������˵����ڡ�\n");

	message_vision(CYN"$N����һֻ����������������Ĵָ�����������������ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢��\n������λ��ϸ��������������\n\n\n"NOR, me);
	busy_time = 30 - lvl/10;
	if(busy_time < 8) busy_time = 8;
	if(busy_time > 20) busy_time = 20;
	me->start_busy(busy_time);
        me->add("jing", -me->query("max_jing")/15);
        me->add("qi", -me->query("max_qi")/15);
if( !environment(me)->query("no_fight"))
{
if (random(40)==1 && me->query("combat_exp") > 1000000)
{
obj=new("/quest/menpaijob/shenlong/menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIY"Ѳ�߹ٱ�"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIY"��������һ�����׺ݵ�Ѳ�߹ٱ���\n"NOR, obj);
message_vision(HIR"$N˵��: ��������˾��һ��ڣ�������������������ˣ�\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return notify_fail("�Ȱ����ٱ�������˵�ɣ�\n");
}
}
	message_vision(HIG"ֻ��$N��ϥ���£�˫�����գ����������дʣ���Ȼ��¶΢Ц: ����!\n\n"NOR,me);

	sp = me->query_skill("count",1)*10 + me->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	
	if ( random(sp) < random(dp)/2 )
{
		write(HIR"���龫���������˰��Σ�ȴ����һ�����á��� \n"NOR);
		me->set("jing", 20);
                me->improve_skill("count",random((int)me->query_int()));
		return notify_fail( HIY"������Ȼ���£�ҡ��ҡͷ��˵�������Եģ�\n"NOR);
}


	where = environment(ob);
	if (!where) return notify_fail("����˲�֪��������Ү...\n");
	if( !(where = environment(ob)) )
	        return notify_fail("����˲�֪��������Ү...\n");

        if( !wizardp(me) && wizardp(ob) ) 
		return notify_fail("�󵨣�����ı����ʦ��\n");


//random(sp) < random(dp)
	if ( random(sp) > random(dp) )
	{
		if (strsrch(file_name(where), "city4") >= 0)
                tell_object(me,    ob->name()+"�����ڳ����ǣ�\n"NOR);
		if (strsrch(file_name(where), "city") >= 0)
                tell_object(me,    ob->name()+"���������ݣ�\n"NOR);
		if (strsrch(file_name(where), "city3") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڳɶ��ǣ�\n");
		else if (strsrch(file_name(where), "city2") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ����ǣ�\n");
		else if (strsrch(file_name(where), "city") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݳǣ�\n");
		else if (strsrch(file_name(where), "dali") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڴ���ǣ�\n");
		else if (strsrch(file_name(where), "death") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڵ����\n");
		else if (strsrch(file_name(where), "emei") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڶ�üɽ�ϣ�\n");
		else if (strsrch(file_name(where), "foshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڷ�ɽ��\n");
		else if (strsrch(file_name(where), "fuzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڸ��ݳǣ�\n");
		else if (strsrch(file_name(where), "gaibang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����ؤ���\n");
		else if (strsrch(file_name(where), "guanwai") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڹ��⣡\n");
		else if (strsrch(file_name(where), "hangzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں��ݳǣ�\n");
		else if (strsrch(file_name(where), "heimuya") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ľ���ϣ�\n");
		else if (strsrch(file_name(where), "hengshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "henshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "henshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "huanggon") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻʹ������\n");
		else if (strsrch(file_name(where), "huashan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻ�ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "lingjiu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������շ��ϣ�\n");
		else if (strsrch(file_name(where), "mingjiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ��������ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "qingcheng") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "quanzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����Ȫ�ݳǣ�\n");
		else if (strsrch(file_name(where), "shaolin") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����������\n");
		else if (strsrch(file_name(where), "shenlong") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����������ϣ�\n");
		else if (strsrch(file_name(where), "songshan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "suzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݳǣ�\n");
		else if (strsrch(file_name(where), "taishan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����̩ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "taohua") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����һ�����\n");
		else if (strsrch(file_name(where), "tianlongsi") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����������\n");
		else if (strsrch(file_name(where), "village") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻ�ɽ�壡\n");
		else if (strsrch(file_name(where), "wudang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����䵱ɽ�ϣ�\n");
		else if (strsrch(file_name(where), "xiakedao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������͵��ϣ�\n");
		else if (strsrch(file_name(where), "xiaoyao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������ң���\n");
		else if (strsrch(file_name(where), "xingxiu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������޺���\n");
		else if ((strsrch(file_name(where), "xuedao") >= 0) ||
		   (strsrch(file_name(where), "xueshan") >= 0))
			tell_object(me,    ob->name()+"�Ĵ��λ���ڴ�ѩɽ�ϣ�\n");
		else if (strsrch(file_name(where), "yanziwu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���������룡\n");
		else if (strsrch(file_name(where), "gumu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ��������ɽ��\n");
		else if (strsrch(file_name(where), "meizhuang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����÷ׯ��\n");
		else if (strsrch(file_name(where), "wanjiegu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������ٹȣ�\n");
		else if (strsrch(file_name(where), "hg") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻʹ����ڣ�\n");
		else if (strsrch(file_name(where), "nio") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����ţ�Ҵ壡\n");			
		else if (strsrch(file_name(where), "feihu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڴ������أ�\n");
		else if (strsrch(file_name(where), "wuguan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����������ݣ�\n");
		else if (strsrch(file_name(where), "village") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻ�ɽ�壡\n");
		else if (strsrch(file_name(where), "wanjiegu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ������ٹȣ�\n");
		else if (strsrch(file_name(where), "pingan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����ƽ���ǣ�\n");
		else if (strsrch(file_name(where), "taohuacun") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����һ��壡\n");
		else if (strsrch(file_name(where), "lingxiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���������ǣ�\n");
		else if (strsrch(file_name(where), "wudujiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����嶾�̣�\n");
		else if (strsrch(file_name(where), "jqg") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ھ���ȣ�\n");
		else if (strsrch(file_name(where), "sdxl") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڽ�ħ�������Ĺ��\n");
		else if (strsrch(file_name(where), "fairyland") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ظ����ĺ�÷ɽׯ��\n");
		else if (strsrch(file_name(where), "changcheng") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ����Ա����ǣ�\n");
		else if (strsrch(file_name(where), "jyguan") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���������Ա������أ�\n");
		else if (strsrch(file_name(where), "lanzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݣ�\n");
		else if (strsrch(file_name(where), "yanjing") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����ྩ��\n");
		else if (strsrch(file_name(where), "jingzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ھ��ݣ�\n");
		else if (strsrch(file_name(where), "kunming") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����������\n");
		else if (strsrch(file_name(where), "ruzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݳǣ�\n");
		else if (strsrch(file_name(where), "lingshedao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ߵ���\n");
		else if (strsrch(file_name(where), "qianjin") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ���ǧ��¥��\n");
		else if (strsrch(file_name(where), "menggu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�����ɹŲ�ԭ��\n");
		else if (strsrch(file_name(where), "yinju") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����һ�ƴ�ʦ�ӣ�\n");
		else if (strsrch(file_name(where), "huizhu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻ��岿�䣡\n");
		else if (strsrch(file_name(where), "tiezhang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���������ţ�\n");
		else if (strsrch(file_name(where), "kunlun") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ��������ɽ��\n");
		else if (strsrch(file_name(where), "baituo") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڰ���ɽ��\n");
		else if (strsrch(file_name(where), "binghuodao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڱ��𵺣�\n");
		else if (strsrch(file_name(where), "gaochang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڸ߲��Թ���\n");
		else if (strsrch(file_name(where), "gumu") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڹ�Ĺ�ɣ�\n");
		else if (strsrch(file_name(where), "heimuya") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ľ�£�\n");
		else if (strsrch(file_name(where), "huanghe") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ڻƺӾ�����\n");
		else if (strsrch(file_name(where), "lingzhou") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������ݣ�\n");
		else if (strsrch(file_name(where), "meizhuang") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ����÷ׯ��\n");
		else if (strsrch(file_name(where), "mingjiao") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ�������̣�\n");
		else if (strsrch(file_name(where), "heimuya") >= 0)
			tell_object(me,    ob->name()+"�Ĵ��λ���ں�ľ�£�\n");

		else return notify_fail( ob->name()+"������ĳ���ط���"+where->query("short")+"������\n");
	}
	if (random(10)>7)
	{
if (userp(ob))
{
                if( (random(lvl/4)) < ob->query("kar") )
                tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......\n"NOR);
}
b1=random(30)+12;
b2=random(20)+9;
           tell_object(me,HIW"�����ˣ�\n" + 
                       chinese_number(b1) + "��ʵս����\n" +
                       chinese_number(b2) + "��Ǳ��\n"+
                       NOR);
me->add("combat_exp", b1);
me->add("potential", b2);

		printf("%s������%s��\n",
		(string)ob->name(), place_desc[random(sizeof(place_desc))]);
		return 1;
	}
if (userp(ob))
{
                if( (random(lvl/4)) < ob->query("kar") )
                tell_object(ob, HIB"��о����񲻶����ƺ������ڰ��п�������......\n"NOR);
}
b1=random(30)+12;
b2=random(20)+9;
           tell_object(me,HIW"�����ˣ�\n" + 
                       chinese_number(b1) + "��ʵս����\n" +
                       chinese_number(b2) + "��Ǳ��\n"+
                       NOR);
me->add("combat_exp", b1);
me->add("potential", b2);

	printf("%s������%s��\n",
		(string)ob->name(),
		(string)where->query("short"));
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: location <��ҵ� ID>

���ָ�����һ�������������֪���Ŀǰ���ڵ�λ��.

HELP
	);
	return 1;
}

